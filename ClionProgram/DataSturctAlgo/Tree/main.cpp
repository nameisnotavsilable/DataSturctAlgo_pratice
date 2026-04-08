#include <KaoYanDataStructure.h>
#include <stdlib.h>
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
// 中序遍历打印树
void inorderPrint(BitNode* root) {
    if (!root) return;
    inorderPrint(root->lchild);
    printf("%c ", root->data);
    inorderPrint(root->rchild);
}
int main() {
    BitTree tree;
    TagPtr tag;
    AssistConstructTree(tree,tag);
    // 4. 验证结果
    printf("中序遍历结果：");
    inorderPrint(tree);
    printf("\n");
    return 0;
}
