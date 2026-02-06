#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef struct
{
    char data[Maxsize];
    int top=-1;
}SqStack;
bool bracketCheck(char str[],int length)
{
    SqStack s;//栈
    //扫描str左括号入栈，扫到右括号pop一个栈元素并配对
    for(int i=0;i<length;i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.top++;
            s.data[s.top] = str[i];//入栈

        } else//扫描到非左括号
        {
            char popElement;//出栈元素
            popElement = s.data[s.top];
            s.top--;
            if (str[i] == ')' && popElement != '(') {
                return false;
            }
            if (str[i] == '}' && popElement != '{') {
                return false;
            }
            if (str[i] == ']' && popElement != '[') {
                return false;
            }
        }
    }
    if(s.top!=-1) return false;//栈还有元素
    else return true;//栈空
}
int main() {
    char str[Maxsize];
    int i = 0;
    char ch;
    printf("请输入字符串（最多个字符，按回车结束）: ");
    while(1) {
        ch = getchar();
        // 遇到换行符或达到数组上限则停止
        if(ch == '\n' || i >= Maxsize) {
            break;
        }

        str[i++] = ch;
    }
    //str[i] = '\0';  // 添加字符串结束标志
    printf("你输入的是: %s\n", str);
    printf("字符串长度: %d\n", i);
    if(bracketCheck(str,i))
    {
        printf(("匹配成功"));
    }else printf("匹配失败");


    return 0;
}
