#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
#define element int
typedef struct
{
    element data;
    int next;
}SLinkList[Maxsize];//静态链表
void Inition(SLinkList sl)//初始化
{
    sl[0].data=0;
    sl[0].next=-1;//头节点默认不指向任何节点”-1指向空“
    for(int i=1;i<Maxsize;i++)
    {
        sl[i].next=-2;//空闲的静态数组next默认-2
    }
}
//增 插入元素
void inser(element e,int pos,SLinkList sl)
{
    if(sl[pos].next!=-2)
    {
        return ;//有元素位置不插入
    }
    int i=0;//指针
    while(sl[i].next!=-1)
    {
        i=sl[i].next;
    }
    sl[pos].data=e;
    sl[i].next=pos;//链接
    sl[pos].next=-1;

}
//读
void output(SLinkList sl)
{
    int i=1;//指针
    while(sl[i].next!=-1)
    {
        printf("第%d个数据%d\n",i,sl[i].data);
        i=sl[i].next;
    }
    printf("第%d个数据%d\n",i,sl[i].data);
}

int main()
{
    SLinkList sl;
    Inition(sl);
    inser(3,1,sl);
    inser(2,9,sl);
    inser(3,3,sl);
    output(sl);//输出测试无误
    return 0;
}