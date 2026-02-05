#include <stdio.h>
#include <stdlib.h>
typedef struct Tree//二叉树数据结构
{
    char data;
    BitNode* Lchild;
    BitNode* Rchild;
    /* data */
}BitNode,*BitTree;
typedef struct//辅助队列dataStuct
{  
    BitNode* p;
    Tag* p_next;
    /* data */
}Tag,*_Tag;
void InitTree_Queue(BitTree &Tree,_Tag &Plist)//初始化树和队列，首个节点内容为0，用colloc，防止脏数据
{

}
void AssistConstuctTree(BitTree &Tree,_Tag &Plist)//
{
    //初始化
    char input;
    Tag* phead;//需要colloc防止指针数据销毁
    Tag* ptail;
    Tag* pcur;
    while(1)
    {
        scanf("%c",&input);
        if(input=='/n' )//没有输入退出
        {
            break;
        }
        //初始化树根节点，队列头节点
        Tag* tagNode=(Tag*)calloc(1,sizeof(Tag));//新建辅助队列节点的指针
        //struct Tag* tagNode;//新建辅助队列节点的指针
        BitNode* treeNode=(BitNode*)calloc(1, sizeof(BitNode));
        //struct BitNode* treeNode;//树节点的指针
        treeNode->data=input;//填树节点数据
        tagNode->p=treeNode;//填队列节点数据
        if(Tree=NULL)//树空队空初始化
        {
            Tree=treeNode;//大树根初始化,指向头节点
            Plist=tagNode;//队列头初始化，指向头节点
            ptail=phead=Plist=pcur;
            continue;//跳出本次循环
        }else//第二个队列节点入队后操作
        {
            ptail->p_next = tagNode;//队列链接
            ptail = tagNode;//队尾指针后移
            if(pcur->p->Lchild==NULL)//树根节点链左树
            {
                pcur->p->Lchild = treeNode;
            }
            if (pcur->p->Rchild == NULL)//树根节点链右树
            {
                pcur->p->Rchild = treeNode;
            }
            if(pcur->p->Lchild!=NULL&& pcur->p->Rchild!=NULL)//双子树不为空，pcur后移
            {
                pcur = pcur->p_next;
            }

        }
        

    }

}
int main()
{
    BitTree Tree;
    _Tag Plist;
    AssistConstuctTree(Tree, Plist);
}