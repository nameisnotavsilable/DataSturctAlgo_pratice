//数据结构wangdao书练习

#include <stdio.h>;
#define maxsize 10
//各种数据结构
//顺序表
typedef struct
{
	int len;//长度
	int list[];//静态表
}SL;
typedef struct
{
	int len;//长度
	int* list;//动态表
}sl, * SL;

typedef struct Node//单链表
{
	int date;
	Node* next;
}node, * linklist;
typedef struct //栈
{
	int data[maxsize];
	int top;//栈针
}sqstack;

typedef struct//队列
{
	int date[maxsize];
	int front, rear;
}Queue;

typedef struct Tree//二叉树数据结构
{
	char data;
	BitNode* Lchild;
	BitNode* Rchild;
	/* data */
}BitNode, * BitTree;
//p19
//08
//10
void _10fuc(SL &r)
{
	//for()遍历，new下标=[下标+（n-p）]%n
}

//arr【k】装有用的数，i查找值和arr【k】是否重复
void fuc_(SL arr)
{
	int k = 0;
	for(int i = 1; i < arr->len; i++)
	{
		if(arr->list[i]==arr->list[k])
			continue;
		else
		{
			k++;
			arr->list[k]=arr->list[i];
		}

	}
}
