#include<iostream>
#include<set>
#include<string.h>
#include<vector>
using namespace std;
/*
Ϊ����������㷨�Ĺ���,û��д��ͨ�õ��㷨���ܶ����ֱ�Ӹ���
����ͨ��ֻ�趯̬������Щ�������� 
*/
int x1[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3};  //��һ����������
int x1D=3;  //����ȡֵֻ�����֣�1,2,3�� 
//�ڶ����������� 
 
char x2[]={'S','M','M','S','S','S','M','M','L','L','L','M','M','L','L'};
int x2D=3;  //ͬ��
 
//��Ӧ����� 
int Y[]={-1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1};
int y1=6;  //6��-1 
int y2=9;  //9��1 
int yD=2;
 
int NUM=15;  //һ��15��ʵ�� 
 
int getx1Num(int userx,int y)
{
	int n=0;
	for(int i=0;i<NUM;i++) //��1������x1=2��ʵ������ 
	{
		if(userx==x1[i]&&y==Y[i])
		 n++;
	} 
	return n;
}
 
int getx2Num(int userx,int y)
{
	int n=0;
	for(int i=0;i<NUM;i++) //��1������x1=2��ʵ������ 
	{
		if(userx==x2[i]&&y==Y[i])
		 n++;
	} 
	return n;
}
 
int main()
{
	int userx1=2;  //������ʵ����һ������ 
	char userx2='S';  //������ʵ���ڶ�������
	
	int r=1;  //�����Ǹ�nameda 
	double py1,py2;  //p(Y=1),p(Y=-1)���������
	py1= ((double)(y1+r))/(NUM+yD*r);  //������ʹ�ʽ:(��һ����ĸ���+r)/(ʵ������+������*r)
	py2=((double)(y2+r))/(NUM+yD*r); 
	cout<<"p(Y=-1)= "<<(y1+r)<<"/"<<NUM+yD*r<<endl;
	cout<<"p(Y=1)= "<<(y2+r)<<"/"<<NUM+yD*r<<endl;
	
	//������������
	int x1Num=getx1Num(userx1,-1);  //����-1�����ж��ٸ�x1=2
	double px1y1=((double)(x1Num+r))/(y1+x1D*r);  //�������ʣ�(1����2�ĸ���+r)/(1��ĸ���+1����Ԫ�صĸ���*r)
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
        cout<<"("<<userx1<<","<<userx2<<")"<<"�������"<<tclass<<endl;
        return 0; 
   
}


