//顺序栈
#include <stdio.h>
#include <stdlib.h>

//重定义函数返回值
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;

//栈最大长度
#define MAXSIZE 100

//顺序栈结构体
typedef struct
{
	ElemType data[MAXSIZE];
	//栈顶指针
	int top;
}SqStack;

//初始化顺序栈
Status InitStack(SqStack* s)
{
	s->top = -1;
	return OK;
}

//判断顺序栈是否为空
Status StackEmpty(SqStack s)
{
	if (s.top == -1)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//求顺序栈长度
int StackLength(SqStack s)
{
	return s.top + 1;
}

//入栈
Status Push(SqStack* s, ElemType e)
{
	//检查栈是否已满
	if (s->top == MAXSIZE - 1)
	{
		return OVERFLOW;
	}
	s->top++;
	s->data[s->top] = e;
	return OK;
}

//出栈
Status Pop(SqStack* s, ElemType* e)
{
	//检查栈是否为空
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->data[s->top];
	s->top--;
	return OK;
}

//取栈顶元素
Status GetTop(SqStack s, ElemType* e)
{
	//检查栈是否为空
	if (s.top == -1)
	{
		return ERROR;
	}
	*e = s.data[s.top];
	return OK;
}

//遍历输出顺序栈
void StackTraverse(SqStack s)
{
	if (s.top == -1)
	{
		printf("顺序栈为空！\n");
		return;
	}
	int i = 0;
	for (i = 0; i <= s.top; i++)
	{
		printf("%d ", s.data[i]);
	}
	printf("\n");
}

//清空顺序栈
Status ClearStack(SqStack* s)
{
	s->top = -1;
	return OK;
}


//主函数
int main()
{
	SqStack s;
	ElemType e;

	//初始化顺序栈
	InitStack(&s);
	printf("顺序栈初始化成功!!!\n");

	//入栈
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);
	Push(&s, 40);
	Push(&s, 50);
	printf("入栈成功!!!\n");
	printf("顺序栈的长度为：%d\n", StackLength(s));

	printf("========================================\n");

	printf("顺序栈的元素为：\n");
	StackTraverse(s);

	printf("========================================\n");

	//取栈顶元素
	GetTop(s, &e);
	printf("栈顶元素为：%d\n", e);

	printf("========================================\n");

	//出栈
	Pop(&s, &e);
	printf("出栈成功!!!\n");
	printf("出栈元素为：%d\n", e);

	printf("========================================\n");

	printf("现在顺序栈的元素为：\n");
	StackTraverse(s);

	printf("========================================\n");

	//清空顺序栈	
	ClearStack(&s);
	printf("清空顺序栈成功!!!\n");
	printf("顺序栈的元素为：\n");
	StackTraverse(s);

}
