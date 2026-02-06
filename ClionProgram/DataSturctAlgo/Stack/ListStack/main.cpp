//注释多行 Ctrl + Shift + /（块注释）
#include <stdio.h>
#include <stdlib.h>
typedef struct Linknode
{
    int data;
    struct Linknode* next;
}*LiStackPointer;//链栈,
//创
void initLiStack(LiStackPointer &L ,int index)//1为带头结点
{
    if(index)
    {
        //带头结点
        L=(LiStackPointer)malloc(sizeof (Linknode));//calloc初始化分配的内存空间
        L->next=NULL;
    }else
    {
        //不带头结点
        L=NULL;
    }
}
//增（push）
void pushListack(LiStackPointer &L,int e)
{
        /*Linknode ss;
        ss.next=L->next;
        L->next=&ss;*/

        LiStackPointer s=(LiStackPointer)malloc(sizeof (Linknode));
        s->data=e;
        s->next=L->next;
        L->next=s;

}
//删（pop）
void popListack(LiStackPointer &L)
{
    if(L!=NULL)
    {
        LiStackPointer s=L->next;//s为待删除节点地址
        L->next=s->next;
        free(s);
    }else
    {
        return;
    }
}
void searchTop(LiStackPointer &L)//读栈顶元素
{
    int output=L->data;
    printf("测试1");
    printf("栈顶元素: %d\n", L->next->data);
}
int main()
{
    printf("测试0");
    LiStackPointer L;
    initLiStack(L,1);
    pushListack(L,222);
    pushListack(L,333);
    searchTop(L);
    return 0;
}
