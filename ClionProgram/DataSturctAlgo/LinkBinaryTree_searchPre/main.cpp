#include <iostream>
#include "KaoYanDataStructure.h"
BitTree pre=NULL;//前驱
BitTree p;//target node
void visit(BitTree q)
{
    if(q==p) p=q  ;
    else pre==q;
}
void InorderFindPre(BitTree tree)
{
    InorderFindPre(tree->lchild);
    visit(tree);
    InorderFindPre(tree->rchild);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
