#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#define N 3                                //�������С

#define Max_Step 30                        //����������

#define MAX 50

typedef struct node                        //������ṹ��

{

int form[N][N];                        //������

int evalue;                            //����ֵ�����

int udirec;                    //�����η���,��ֹ�����Ƶ���һ״̬,1��2��3��4��

struct node *parent;                    //���ڵ�

}Graph;

Graph *Qu[MAX];                            //����

Graph *St[MAX];                            //��ջ

/*��ӡ������*/

void Print(Graph *The_graph)

{

int i,j;

if(The_graph==NULL)

printf("ͼΪ��\n");

else

{

printf("-----------------------------------------\n");

for(i=0;i<N;i++)

{

printf("|\t");

for(j=0;j<N;j++)

{

printf("%d\t",The_graph->form[i][j]);      //������ӡ

}

printf("\t|\n");

}

printf("|\t\t\t\t���:%d\t|\n",The_graph->evalue);  //�����ʾ

printf("-----------------------------------------\n");

}

}

/*���ۺ���*/

int Evaluate(Graph * The_graph,Graph * End_graph)

{

int value=0;    //�����

int i,j;

for(i=0;i<N;i++)

{

for(j=0;j<N;j++)

{

if(The_graph->form[i][j]!=End_graph->form[i][j])  //����������Ƚϲ��

value++;

}

}

The_graph->evalue=value;

return value;

}

/*�ƶ�������*/

Graph *Move(Graph *The_graph,int Direct,int CreateNew_graph)

{

Graph *New_graph;

int HasGetBlank=0;              //�Ƿ��ȡ�ո�λ��

int AbleMove=1;                //�Ƿ���ƶ�

int i,j,t_i,t_j,x,y;

for(i=0;i<N;i++)                //��ȡ���и�λ��

{       

for(j=0;j<N;j++)

{

if(The_graph->form[i][j]==0)

{

HasGetBlank=1;

break;

}

}

if(HasGetBlank)

break;

}

//printf("�ո�λ��:%d,%d\n",i,j);

t_i=i;t_j=j;

switch(Direct)  //�ƶ��ո�

{

case 1:    //��

t_i--;

if(t_i<0)

AbleMove=0;

break;       

case 2:    //��

t_i++;

if(t_i>=N)

AbleMove=0;

break;       

case 3:    //��

t_j--;

if(t_j<0)

AbleMove=0;

break;     

case 4:    //��

t_j++;

if(t_j>=N)

AbleMove=0;

break;     

};

if(!AbleMove)  //�������ƶ��򷵻�ԭ�ڵ�

{

return The_graph;

}

if(CreateNew_graph)

{

New_graph=(Graph *)malloc(sizeof(Graph));        //���ɽڵ�

for(x=0;x<N;x++)

{

for(y=0;y<N;y++)

New_graph->form[x][y]=The_graph->form[x][y]; //����������

}

}

else

{

New_graph=The_graph;

}

/*�ƶ���*/

New_graph->form[i][j]=New_graph->form[t_i][t_j];

New_graph->form[t_i][t_j]=0;     

return New_graph;

}

/*��������*/

Graph *Search(Graph *Begin,Graph *End)

{

Graph *g1,*g2,*g;

int Step=0;          //���

int Direct=0;

int i;

int front,rear;

front=rear=-1;      //���г�ʼ��

g=NULL;

rear++;              //���

Qu[rear]=Begin;

while(rear!=front)  //�Ӳ���
{

front++;//����

g1=Qu[front];

//printf("��ʼ��%d��ͼ:\n",front);

//Print(g1);

for(i=1;i<=4;i++)              //�ֱ���ĸ������Ƶ������ӽڵ�

{

Direct=i;

if(Direct==g1->udirec)    //�������η���

continue;       

g2=Move(g1,Direct,1);      //�ƶ�����

if(g2!=g1)                //�����Ƿ�����ƶ�

{

Evaluate(g2,End);      //���½ڵ�����

//printf("��ʼ�����ĵ�%d��ͼ:\n",i);

//Print(g2);

if(g2->evalue<=g1->evalue+1)    //�Ƿ�Ϊ��Խ�ڵ�

{

g2->parent=g1;

switch(Direct)              //�������η���,��ֹ������

{

case 1:

g2->udirec=2;break;

case 2:

g2->udirec=1;break;

case 3:

g2->udirec=4;break;

case 4:

g2->udirec=3;break;

}

rear++;

Qu[rear]=g2;                //�洢�ڵ㵽���������

if(g2->evalue==0)          //Ϊ0��,�������

{

g=g2;

i=5;

}

}

else

{

free(g2);          //���ʽڵ�����

g2=NULL;

}

}

}

Step++;                    //ͳ�����

if(Step>Max_Step)

return NULL;

if(g!=NULL)

break;

}

return g;

}

/*��ʼ��һ��������ṹ��*/

Graph *CR_BeginGraph(Graph *The_graph)

{

int M=10;            //����ƶ�����

int Direct;

int i,x,y;

Graph *New_graph;

New_graph=(Graph *)malloc(sizeof(Graph));          //���ɽڵ�

for(x=0;x<N;x++)

{

for(y=0;y<N;y++)

New_graph->form[x][y]=The_graph->form[x][y];  //����������

}

for(i=0;i<M;i++)

{   

Direct=rand()%4;

//printf("%d\n",Direct);

New_graph=Move(New_graph,Direct,0);       

}

New_graph->evalue=0;

New_graph->udirec=0;

New_graph->parent=NULL;

//Print(New_graph);

return New_graph;

}

/*������*/

void main()

{   

/*Graph Begin_graph={

{{2,8,3},{1,0,4},{7,6,5}},0,0,NULL

};*/

/*Graph Begin_graph={

{{2,0,1},{4,6,5},{3,7,8}},0,0,NULL

};*/

/*Ŀ��������*/

Graph End_graph={

{{1,2,3},{8,0,4},{7,6,5}},0,0,NULL

};

Graph *G,*P;

/*��ʼ������*/

Graph *Begin_graph;

int top=-1;

Begin_graph=CR_BeginGraph(&End_graph);  //���������ʼ������

Evaluate(Begin_graph,&End_graph);        //�Գ�ʼ����������

printf("��ʼ������:\n");

//printf("udirec:%d\tparent:%d\n",Begin_graph->udirec,Begin_graph->parent);

Print(Begin_graph);

printf("Ŀ��������:\n");

Print(&End_graph); 

/*ͼ����*/

G=Search(Begin_graph,&End_graph);

//Print(G);

/*��ӡ*/ 

if(G)

{

//��·������

P=G;

//ѹջ

while(P!=NULL)

{

top++;

St[top]=P;

P=P->parent;

}

printf("\n<<<<<<<<<<<<<<<<<�������>>>>>>>>>>>>>>>>\n");     

/*��ջ��ӡ*/

while(top>-1)

{

P=St[top];

top--;

Print(P);

}

printf("\n<<<<<<<<<<<<<<<<<<���!>>>>>>>>>>>>>>>>>>\n");

}

else

printf("�����������.���Ϊ%d\n",Max_Step);

}            //�����������ȷ�Χ����ֹ�����ڴ�Խ��