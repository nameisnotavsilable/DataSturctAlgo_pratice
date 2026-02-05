#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// OJhomework4.1判断对称数
void Extract_digitals(int* nums, int num);
void Calculate(int* countTemp, int n);
int main()
{
	//Lesson 1.1
	/*printf("hello world\n");
	return 0;*/
	//Lesson 1.2
	//int i;
	//char c;
	//scanf("%d", &i);
	//printf("%d\n", i);
	//scanf("%c", &c);//%c会读取所有字符，包括空格、换行符，此时输入款冲区还有‘\n'
	//printf("c=%c\n", c);
	//return 0;
	//Lesson 1.3
	/*int i; char ch; float d; int ret;
	ret=scanf("%d %c%f", &i, &ch, &d);
	printf("i=%d\nch=%c\nd=%f\n", i, ch, d);*/
	//Test
	/*char arr[10];
	scanf("%s", arr);
	printf("%s\n", arr);
	printf("arr length=%d\n", (int)strlen(arr));*/
	//OJhomework3.1判断闰年
	/*int year;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}*/
	//OJhomework3.2
	/*int i;
	char j;
	float k;
	scanf("%d %c %f", &i, &j, &k);
	float sum = i + j + k;
	printf("%.2f\n", sum);*/
	//OJhomework4.1判断对称数
	//int num; int count=0;
	//scanf("%d", &num);
	////找出num的位数
	////count = Caculate(num);
	//Calculate(&count,num);
	//printf("count=%d\n", count);
	////分离出来的数存在数组中
	////int nums[count];error:栈区变量是静态的，必须在编译时确定其大小
	//int* nums = (int*)malloc(count * sizeof(int));//动态分配内存，malloc分配到具体字节，需手动释放，是地址
	//if (nums == NULL) 
	//{
	//	printf("Memory allocation failed\n");
	//	return 1;
	//}
	//Extract_digitals(nums,num);//
	////历遍1至num/2位，每次取出对应的首尾位进行比较，比较的两位和为n+1
	//for (int i = 0; i < count / 2; i++)
	//{
	//	//取出对应的首尾位进行比较
	//	int left = nums[i];
	//	int right = nums[count - i - 1];
	//	if (left != right)
	//	{
	//		printf("no\n");
	//		return ;
	//	}
	//	printf("yes\n");
	//}
	//free(nums);//释放动态分配的内存
	//OJhomework4.2
	//OJhomework4.2计算n!
	//int inputnum;
	//int result = 1;
	//scanf("%d", &inputnum);
	//if (inputnum >= 1 && inputnum <= 10) 
	//{
	//	for (int i = 1; i <= inputnum; i++)
	//	{
	//		result = result * i;//n!
	//	}
	//	printf("result=%d", result);
	//}else
	//{
	//	printf("input uncorrectly,please try agin");
	//}
	//OJhomework4.3
	//OJhomework5.1
	//int inputnum; int flagnums = 0;//flagnums记录输入的数字个数
	//scanf("%d", &inputnum);//输入数字个数
	//int *nums=(int*)malloc(sizeof(int)*inputnum);
	//for(int i=0;i<inputnum;i++)
	//{
	//	scanf("%d", &nums[i]);
	//}
	//for(int i=0;i<inputnum;i++)
	//{
	//	if(nums[i]==2)
	//	{
	//		flagnums++;
	//	}
	//}
	//printf("Number 2 appears times=%d\n", flagnums);
	//OJhomework5.2
	//char c[10]; char d[10];
	//printf("inputstring:");
	//fgets(c, sizeof(c), stdin);
	//
	//int len = strlen(c);
	//for (int i = len - 1, j = 0; i >= 0; i--, j++) {
	//	d[j] = c[i];
	//}
	//d[len] = '\0'; // 添加字符串结束符
	//puts(d);
	//int result = strcmp(c, d);
	//if(result<0)
	//{
	//	printf("%d\n", -1);
	//}else if(result>0)
	//{
	//	printf("%d\n", 1);
	//}
	//else
	//{
	//	printf("%d\n", 0);
	//}
	//OJhomework6.1
	/*int n;
	scanf("%d", &n);
	n = Change(n);
	printf("%d\n", n);*/
	//OJhomework6.2
	/*int n;
	scanf("%d", &n);
	char* p;
	p = (char*)malloc(n * sizeof(char));
	scanf("%c", p);
	gets(p);
	if (strlen(p) < n) {
		printf("%s\n", p);
	}*/
	//OJhomework7.1
	//OJhomework8.1	
	struct student{
		int id;
		char name[20];
		char sex[9];
	};
	struct student stu1 = { 0,NULL,NULL };
	scanf("%d %s %s", &stu1.id, stu1.name, &stu1.sex);
	printf("%d %s %s", stu1.id, stu1.name, stu1.sex);


	return 0;
}
//Son functions
void Extract_digitals(int* nums, int num)
{
	int i = 0;
	while (num > 0)
	{
		nums[i] = num % 10; // 直接使用 nums[i]，而不是 (*nums)[i]
		num = num / 10;
		i++;
	}
}
void Calculate(int* countTemp, int n)
{
	//int count = 0;
	while (n > 0)
	{
		(*countTemp)++;
		n = n / 10;
	}

}
//OJ6.1
int Change(int n) {
	int result;
	result = n / 2;
	return result;
}

