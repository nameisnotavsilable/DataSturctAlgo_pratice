#include<stdio.h>
#include<stdlib.h>
typedef int element;

//线性表顺序查找
typedef struct
{
	int len;//长度
	int list[];//静态表
}SL;
typedef struct 
{
	int len;//长度
	int* list;//动态表
}sl,*SL;
void init_list(SL L,int len)
{
	L->len = len;
	L->list = (int*)malloc(L->len * sizeof(element));

}

//算法
void swap(int i, int j)
{

}
//冒泡排序
void pupasort(SL &L)
{
	bool flag = false;
	for(int i= L->len - 1; i >=0;i--)//分割范围排n-1轮
	{
		for (int j = 0; j+1 < i;j++)//范围内从小到大排序,放入max
		{
			if(L->list[i]> L->list[j])
			{
				swap(L->list[i], L->list[j]);
				flag = true;
			}
			if (flag==false) return;
		}
	}
}
int slReserch(SL L,element key)
{
	int pos=0;//position
	for(int i=L->len-1;i>=0;i--)
	{
		if (key == L->list[i])
		{
			pos = i;//记录位置
		}
	}
	return pos;
}
//二分查找


//二叉排序树建树
//递归建树
typedef struct Tree//二叉树数据结构
{
	element data;
	BitNode* Lchild;
	BitNode* Rchild;
	/* data */
}BitNode, * BitTree;
int insertTreeNode(BitTree& t, element key)
{
	BitNode * treeNode = (BitNode*)calloc(1, sizeof(BitNode));
	t = treeNode;
	t->data = key;
	if (t->data==key )//插入相同数据返回
	{
		return 0;
	}
	if(key<t->data)//联想：递归就写循环里的第一遍？先插入后走路,倒顺序？
	{
		t = t->Lchild;
		return insertTreeNode(t, key);
	}
	else
	{
		t = t->Rchild;
		return insertTreeNode(t, key);
	}
	//总结：先做节点插入，后走路
	//return 1;
}

//quitSort
// 交换元素
void swap(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

}
//确认分隔值正确位置
int Segment(SL &sl,int low,int high)
{
	int seg = sl->list[low];//默认最左边放分割值
	int segpos = low;//默认分割值位置
	low++;
	while(high>=low)
	{
		//low -》 high替罪羊
		if(sl->list[low]>seg)
		{
			if(sl->list[high]<seg)
			{
				//get sucess 交换
				swap(sl->list[low], sl->list[high]);
			}
			else
			{
				high--;
			}
		}
		if(sl->list[low] <= seg)
		{
			low++;
		}
	}
	swap(sl->list[segpos], sl->list[high]);//find seg put into corret position
	segpos = high;
	return segpos;
}
//分治递归排序
void quitSort(SL& sl, int low, int high)
{
	int segpos=Segment(sl, low, high);
	quitSort(sl,low,segpos-1);//排左边
	quitSort(sl,segpos+1,high);//右边
}