#include <stdio.h>;
#define maxsize 10
typedef struct //栈
{
    int data[maxsize];
    int top;//栈针
}sqstack;
void Initial_stack(sqstack& s)//初始化栈
{
    s.top = -1;
    //赋值
}
bool push(sqstack& s, int num)//入栈
{
    if (s.top = maxsize - 1) return false;//判断栈空
    s.top = s.top + 1;//
    s.data[s.top] = num;
    return true;
}
bool pop(sqstack& s, int& read)//出栈
{
    if (s.top = -1) return false;
    read = s.data[s.top];
    //s.data[s.top]=0;//出栈
    s.top--;
    return true;
}
