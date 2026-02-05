#include <stdio.h>;
#include <stdlib.h>;
#define maxsize 10
typedef struct //顺序（存储）栈
{
    int data [maxsize];
    int top;//栈针
}sqstack;
void Initial_stack(sqstack &s)//初始化栈
{
    s.top=-1;
    //赋值
}
bool push(sqstack &s,int num)//入栈
{
    if(s.top=maxsize-1) return false;
    s.top=s.top+1;//
    s.data[s]=num;
    return true;
}
bool pop(sqstack &s,int &read)//出栈
{
    if(s.top=-1) return false;
    read=s.data[s.top];
    //s.data[s.top]=0;//出栈
    s.top--;
    return true;
}
/////////////////////队列顺序存储/////////////
/////////////////////#非循环队列#/////////////
typedef struct//非循环队列数据结构
{
    int data[maxsize];
    int front,rear;
}Queue;
void InitQueue(Queue &q)//初始化队列
{
    q.front=0;
    q.rear=0;//队空
}
bool EnQueue(Queue &q,int x)//入队
{
    //检查队满,r先入队再加1
    if(q.rear==maxsize+1)//检查队满
    {
        return false;
    }
    data[q.rear]=x;//入队
    q.rear++;
    return true;
}
//出队FIFO,检查队空,读取数据front再加1
bool OutQueue(Queue &q,int x)
{
    if(q.rear=q.front)//队空
    {
        return false;
    }
    x=q.data[q.front];
    q.front++;
    return true;
}
/////////////////////#非循环队列#/////////////
/////////////////////#循环队列#/////////////
typedef struct//循环队列数据结构
{
    int data[maxsize];
    int front,rear;
}Queue;
void InitQueue(Queue &q)//初始化队列
{
    q.front=0;
    q.rear=0;//队空
}
bool EnQueue(Queue &q,int x)//入队
{
    //检查队满,r先入队再加1
    if((q.rear+1)%maxsize==q.front)//检查队满
    {
        return false;
    }
    data[q.rear]=x;//入队
    q.rear=(q.rear+1)%maxsize;
    return true;
}
//出队FIFO,检查队空,读取数据front再加1
bool OutQueue(Queue &q,int x)
{
    if(q.rear=q.front)//队空
    {
        return false;
    }
    x=q.data[q.front];           
    q.front=(q.front+1)%maxsize;
    return true;
}

/////////////////////#循环队列#/////////////
/////////////////////队列顺序存储/////////////

/////////////////////队列链式存储/////////////
typedef struct
{
    int data;
    QueueNode* next;//指向下一个节点
}QueueNode;
//双指针
typedef struct
{
    QueueNode* front,rear;
}LinkQueue;
void InitLinkQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(QueueNode*)malloc(sizeof(QueueNode));//f,r指向链表头节点
    Q.front->next=null;
}
//入队 尾插法
bool EnLinkQueue(LinkQueue &Q,int x)
{
    //链式存储没有队满
    //声明新节点，链接r
    QueueNode q=(QueueNode*)malloc(sizeof(QueueNode));//malloc不会栈销毁
    q.data=x;
    Q.rear=q;
    return true;
}
//出队 头出法
bool OutLinkQueue(LinkQueue &Q,int x)
{
    //q指向要删除的节点
    QueueNode q=(QueueNode*)malloc(sizeof(QueueNode));//malloc不会栈销毁
    Q.front->next=q;
    //不是删除最后一个元素
    if(q.next!=null)
    {
        Q.front->next=q->next;
    }
    //删除最后一个元素
    Q.front->next=null;
    //断链
    free(q);
}


/////////////////////队列链式存储/////////////
