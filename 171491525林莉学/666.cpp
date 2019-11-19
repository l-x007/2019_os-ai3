#include<iostream>
#include<set>
#include<string.h>
#include<vector>
using namespace std;
/*
为了清晰表达算法的过程,没有写成通用的算法，很多参数直接给出
如需通用只需动态计算这些参数即可 
*/
int x1[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3};  //第一个特征向量
int x1D=3;  //就是取值只有三种（1,2,3） 
//第二个特征向量 
 
char x2[]={'S','M','M','S','S','S','M','M','L','L','L','M','M','L','L'};
int x2D=3;  //同上
 
//对应的类别 
int Y[]={-1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1};
int y1=6;  //6个-1 
int y2=9;  //9个1 
int yD=2;
 
int NUM=15;  //一共15个实例 
 
int getx1Num(int userx,int y)
{
	int n=0;
	for(int i=0;i<NUM;i++) //在1类中找x1=2的实例个数 
	{
		if(userx==x1[i]&&y==Y[i])
		 n++;
	} 
	return n;
}
 
int getx2Num(int userx,int y)
{
	int n=0;
	for(int i=0;i<NUM;i++) //在1类中找x1=2的实例个数 
	{
		if(userx==x2[i]&&y==Y[i])
		 n++;
	} 
	return n;
}
 
int main()
{
	int userx1=2;  //待分类实例第一个特征 
	char userx2='S';  //待分类实例第二个特征
	
	int r=1;  //就是那个nameda 
	double py1,py2;  //p(Y=1),p(Y=-1)的先验概率
	py1= ((double)(y1+r))/(NUM+yD*r);  //先验概率公式:(第一个类的个数+r)/(实例个数+类别个数*r)
	py2=((double)(y2+r))/(NUM+yD*r); 
	cout<<"p(Y=-1)= "<<(y1+r)<<"/"<<NUM+yD*r<<endl;
	cout<<"p(Y=1)= "<<(y2+r)<<"/"<<NUM+yD*r<<endl;
	
	//计算条件概率
	int x1Num=getx1Num(userx1,-1);  //计算-1类中有多少个x1=2
	double px1y1=((double)(x1Num+r))/(y1+x1D*r);  //条件概率：(1类中2的个数+r)/(1类的个数+1类中元素的个数*r)
	cout<<"p(x1=2|Y=-1)= "<<x1Num+r<<"/"<<y1+x1D*r<<endl;
	
        int x2Num=getx1Num(userx1,1);
        double px1y2=((double)(x2Num+r))/(y2+x2D*r);
        cout<<"p(x1=2|Y=1)= "<<x2Num+r<<"/"<<y2+x2D*r<<endl;
   
        int x21Num=getx2Num(userx2,-1);
        double px2y1=((double)(x21Num+r))/(y1+x1D*r);
        cout<<"p(x2='S'|Y=-1)= "<<(x21Num+r)<<"/"<<(y1+x1D*r)<<endl;
   
        int x22Num=getx2Num(userx2,1);
        double px2y2=((double)(x22Num+r))/(y2+x2D*r);
        cout<<"p(x2='S'|Y=1)= "<<(x22Num+r)<<"/"<<(y2+x2D*r)<<endl;
   
        double re1=py1*px1y1*px2y1;
        double re2=py2*px1y2*px2y2;
        cout<<re1<<"\t"<<re2<<endl;
        int tclass=re1>re2?-1:1;
        cout<<"("<<userx1<<","<<userx2<<")"<<"的类别是"<<tclass<<endl;
        return 0; 
   
}


