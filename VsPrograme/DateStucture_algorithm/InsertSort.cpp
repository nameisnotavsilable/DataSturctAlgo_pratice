//插入排序
#define Maxnum 10
#include<stdio.h>
typedef struct
{
	int len;//长度
	int list[];//静态表
}SL;
void insertSort(SL& l)
{
	for (int i = 1; i < l.len; i++)
	{
		int insertval = l.list[i];//要插入元素
		for (int j = i; j >= 0; j--)//排序范围内排序,自己的写法
		{
			if(insertval<l.list[j-1])
			{
				l.list[j] = l.list[j-1];//后移一位
				l.list[j - 1] = insertval;//插入
			}
		}
	}
}