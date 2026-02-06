#include <stdio.h>;
#define Maxsize 10
///////////////////Queue顺序存储/////////////////////
//非循环队列
typedef struct
{
	int date[Maxsize];
	int front, rear;
}Queue;
bool InitQueue(Queue &q)//初始化
{
	q.front = 0; q.rear = 0;//队头队尾指针默认为0
}
bool CheckIsEempty(Queue &q)//判断队空
{
	if(q.rear=q.front)
	{
		return true;//队空
	}
	else
	{
		return false;
	}
}
bool CheckIsFull(Queue& q)//判断队满
{
	if (q.rear == Maxsize)//rear先加一，再插入
	{
		return true;
	}
	else
	{
		return false;
	}
}


//循环队列


///////////////////Queue顺序存储/////////////////////

///////////////////Queue链式存储/////////////////////



///////////////////Queue链式存储/////////////////////


