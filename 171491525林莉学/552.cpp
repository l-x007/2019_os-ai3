#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

#define MAX_CITY_NUM 100
#define T0 2000
#define T 1e-5
#define ALPHA 0.98
#define L 20000

struct path{
    int route[MAX_CITY_NUM];
    double dis;
};

double w[MAX_CITY_NUM][MAX_CITY_NUM];
int num;
double s = 0;
path p0;

void Init_City()
{
    cout << "Please input the number of cities:" << endl;
    cin >> num;
    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j)
            cin >> w[i][j];
}

void Init_path()
{
    p0.dis = 0;
    for (int i = 0; i < num; ++i)
    {
        p0.route[i] = i;
        if (i != num - 1)
            p0.dis += w[i][i + 1];
    }
    p0.dis += w[num - 1][0];
}

path generate(path p)
{
    int x = 0, y = 0;
    while (x == y)
    {
        x = (int)(num * (rand() / (RAND_MAX + 1.0)));
        y = (int)(num * (rand() / (RAND_MAX + 1.0)));
    }
    path gen = p;
    int tmp;
    tmp = gen.route[x];
    gen.route[x] = gen.route[y];
    gen.route[y] = tmp;

    gen.dis = 0;
    for (int i = 0; i < num - 1; ++i)
        gen.dis += w[gen.route[i]][gen.route[i + 1]];
    gen.dis += w[gen.route[num - 1]][gen.route[0]];
    return gen;
}



void TSP_SA()
{
    double t = T0;
    srand(time(NULL));
    path cur = p0;
    path next = p0;
    int bChange;
    while (t > T)
    {
        bChange = 0;
        for (int i = 0; i < L; ++i)
        {
            next = generate(cur);
            double df = next.dis - cur.dis;
            if (df <= 0)
            {
                cur = next;
                bChange = 1;
            }
            else
            {
                double rndp = rand() / (RAND_MAX + 1.0);
                double eps = exp(-df / t);
                if (eps > rndp && eps < 1)
                {
                    cur = next;
                    bChange = 1;
                }
            }

        }

        if (cur.dis < p0.dis)
            p0 = cur;

        t *= ALPHA;
        if (!bChange)
            ++s;
        else
            s = 0;

        if (s == 2)
            break;
    }
}

int main()
{
    Init_City();
    Init_path();
    TSP_SA();

    cout << "The best path is:" << endl;
    for (int i = 0; i < num; ++i)
            cout << p0.route[i] << " -> ";
    cout << p0.route[0] << endl;
    cout << "The distance of the best path is: " << p0.dis << endl;
    system("pause");
    return 0;
}