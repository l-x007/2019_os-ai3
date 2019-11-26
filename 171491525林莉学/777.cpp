#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double matrix[4][2]={{1,1},{4,1},{5,1},{8,1}};   //样本
    double result[4]={5,11,13,19.5};                 //期望值
    double err_sum[4] = {0,0,0,0};                   //各个样本的误差
    double theta[2] = {1,6};                         //Θ,初始值随机
    double err_square_total = 0.0;                   //方差和
    double learning_rate = 0.01;                     //学习率
    int ite_num;                                     //迭代次数

    for(ite_num = 0; ite_num <= 10000; ite_num++) 
    {                               
        int i,j,k;
        err_square_total = 0.0; 

        for(i = 0; i < 4; i++)          
        {
            double h = 0;         
            for(j = 0; j < 2; j++)   
                h += theta[j]*matrix[i][j];    

            err_sum[i] = result[i] - h;  
            err_square_total += 0.5*err_sum[i]*err_sum[i];
        }

        if(err_square_total < 0.05)  //0.05表示精度
             break;

        for(j = 0; j < 2; j++)
        {
            double sum = 0;
            for(k = 0; k < 4; k++)   //所有样本都参与计算
                sum += err_sum[k]*matrix[k][j]; 
            theta[j] = theta[j] + learning_rate*sum; //根据上面的公式计算新的Θ
        }
    }

    printf(" @@@ Finish, ite_number:%d\n, err_square_total:%lf, theta[0]:%lf, theta[1]:%lf\n", ite_num, err_square_total, theta[0], theta[1]);

    return 0;
}