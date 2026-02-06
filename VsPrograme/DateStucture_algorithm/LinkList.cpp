#define Maxnum 10
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///////////////线性表的顺序表增删改查////////////////
/*
void initial(line L);//初始化线性表
void addlegth(line L);//增加线性表长度
//dynamic动态顺序表
typedef struct
{
    int* p;
    int maxsize;//数组长度
    //int length;//当前长度
}line;
int main()
{
    line line00;
    initial(line00);
    //////////////扩展线性表长度
    addlegth(line00, 10);

}
void initial(line L)//初始化线性表值
{
    L.maxsize = Maxnum;
    L.p = (int*)malloc(L.maxsize * sizeof(int));
    L.maxsize = 0;
    for (int i = 0; i < L.maxsize; i++)
    {
        L.p[i] = 0;//初始化线性表值
    }
}
void addlegth(line L, int len)//扩展线性表长度 增
{
    L.maxsize = L.maxsize + len;
    ////////申明临时指针域作为更改的数据的临时容器，赋给线性表数据域后，最后释放///////////
    int* original = L.p;//旧的数组
    L.p = (int*)malloc((L.maxsize + len) * sizeof(int));//p指向新数组
    //旧的线性表copy到新数组
    for (int i = 0; i < L.maxsize; i++)
    {
        L.p[i] = original[i];
    }
    free(original);
    ////////申明临时指针域作为更改的数据的临时容器，赋给线性表数据域后，最后释放///////////
}
void DeleteFactor(line L, int position)//删除顺序表某个值 删
{

    if (position >= L.maxsize) return ;//超出表的长度
    for (int j = L.maxsize - 2; j >= position - 1; j--)//j是左操作数。后一位赋值给上一位，直到删除元素位置
    {
        L.p[j] = L.p[j + 1];
    }
    int* original = L.p;//旧的数组,临时存新数组数据
    L.p = (int*)malloc((L.maxsize - 1) * sizeof(int));//p指向新数组
    //旧的线性表copy到新数组
    for (int i = 0; i < L.maxsize; i++)
    {
        L.p[i] = original[i];
    }
    free(original);
    return ;
}
void AlterFactor(line L, int position, int num)//改变数组某个位置某个值 改
{
    L.p[position] = num;
    ////////申明临时指针域作为更改的数据的临时容器，赋给线性表数据域后，最后释放///////////
    int* original = L.p;//旧的数组
    L.p = (int*)malloc((L.maxsize) * sizeof(int));//p指向新数组
    //旧的线性表copy到新数组
    for (int i = 0; i < L.maxsize; i++)
    {
        L.p[i] = original[i];
    }
    free(original);
    ////////申明临时指针域作为更改的数据的临时容器，赋给线性表数据域后，最后释放///////////
}
void ObeserveFactor(line L, int position)// 查
{
    int result;
    result = L.p[position];
    printf("查找值为:%d/n", result);
}
*/
///////////////线性表的顺序表增删改查////////////////

///////////////线性表的*单链表*增删改查////////////////
typedef struct Node//单链表
{
    int date;
    Node* next;
}node, * linklist;
//初始化单链表
void initialLinklist(linklist L, int index)
{
    if (index != 0)
    {
        //不带头节点
        L=NULL;
    }
    else
    {
        //带头节点
        L = (node*)malloc(sizeof(node));
        L->next = NULL;
    }
}
//单链表 插入
//前插法方法二 传入节点p位置，两步走：第一步链接节点，第二步值交换
bool preinsert01(node* p, int num)//p需要引用&吗？？？能否直接传链表引用L
{
    //node a;a.data = 0;

    node* s = (node*)malloc(sizeof(node));
    if (s == NULL)
    {
        //内存不足
        return false;
    }
    s->date = num;
    s->next = p->next;//第一步
    p->next = s;
    p->date = s->date;//第二步
    s->date = p->date;
	return true;
}
//前插法方法一 传入头节点找到前驱节点
bool preinsert00(linklist& L, node* p, int num)
{
    node* f = L;//f是扫描节点
    while (f->next != p)//找到前驱节点
    {
        f = f->next;
    }
    node* s = (node*)malloc(sizeof(node));//新节点
    if (s == NULL)
    {
        //内存不足
        return false;
    }
    s->date = num;
    f->next = s;//链接节点
    s->next = p; free(p);
	return true;
}
//删除某节点
//删除头节点
bool deletehead(linklist& L){
    if (L == NULL) return false;//空表
    node* p = L;//p是头节点
    L = L->next;
    free(p);
    return true;
}
//删除指定节点 (传入头节点和待删除节点)
bool deletefactor(linklist& L, node* p)
{
    if (L == NULL) return false;//空表
    if (p == L) return deletehead(L);//删除头节点
    node* f = L;//f是扫描节点
    while (f->next != p)//找到前驱节点
    {
        f = f->next;
    }
    f->next = p->next;
    free(p);
    return true;
}
//删除末节点
bool deleterear(linklist& L) 
{
    //找到末节点，扫描节点指向末节点前驱
    node* rear = L;
    node* f = L;
    while (rear->next != NULL) 
    {
        rear = rear->next;
    }
    while (f->next != rear)
    {
        f = f->next;
    }
    f->next = NULL;//删除末节点
    return true;
}
///////////////线性表的*单链表*增删改查////////////////