#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int find1=0,dx[9]={0,1,1,-1,-1,2,2,-2,-2},dy[9]={0,2,-2,2,-2,1,-1,1,-1},t,a[10][10],sx,sy;
char w;
int goal[5][5]={
	{1,1,1,1,1},
	{0,1,1,1,1},
	{0,0,2,1,1},
	{0,0,0,0,1},
	{0,0,0,0,0}
};
int check()
{
	int dif=0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			if(goal[i][j]!=a[i][j])
				dif++;
		}
	return dif;
}
void iddfs(int x,int y,int de,int k)
{
	if(de==k)
	{
		if(!check())
			find1=1;
		return;
	}
	for(int i=1;i<=8;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(x1<0||x1>4||y1<0||y1>4)
			continue;
		swap(a[x][y],a[x1][y1]);
		if(de+check()<=k)
            iddfs(x1,y1,de+1,k);
		swap(a[x][y],a[x1][y1]);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<5;i++){
            getchar();
			for(int j=0;j<5;j++)
			{
				scanf("%c",&w);
				if(w=='*')
				{
					a[i][j]=2;
					sx=i;
					sy=j;
				}
				else
					a[i][j]=w-'0';
			}
		}
		int k;
		for(k=0;k<=15;k++)
		{
			iddfs(sx,sy,0,k);
			if(find1)
				break;
		}
		if(k>15)
			printf("-1\n");
		else
			printf("%d\n",k);
		find1=0;
	}
}
