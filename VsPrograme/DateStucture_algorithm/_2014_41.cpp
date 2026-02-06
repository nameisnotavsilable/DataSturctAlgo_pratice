#include<stdio.h>
#include<stdlib.h>
typedef int elemente;
typedef struct s1
{
	elemente weight;//权值
	struct NewTreeNode* left;//左子树指针
	struct NewTreeNode* right;//右子树指针
}NewTreeNode, * Ptree;
elemente WPLcaculation(Ptree T)
{
	elemente WPL;
	int routeLength;//路径长度
	//判断是否是叶子节点，是加入wpl，不是继续递归

	//前序遍历递归
	if (T->left == NULL && T->right == NULL) {
		//叶子节点
		WPL = WPL + routeLength * T->weight;
	}
	if (T->left != NULL)
	{
		routeLength++;
		WPLcaculation(T->left);
	}
	if (T->right != NULL)
	{

		routeLength++;
		WPLcaculation(T->right);
	}
	return WPL;
}