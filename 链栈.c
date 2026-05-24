//链栈
#include <stdio.h>
#include <stdlib.h>

//重定义函数返回值
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;

//链栈结构体
typedef struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

//初始化链栈
Status InitLinkStack(LinkStack* s)
{
	*s = NULL;
	return OK;
}

//判断链栈是否为空
Status LinkStackEmpty(LinkStack s)
{
	return s == NULL ? OK : ERROR;
}

//求链栈长度
int StackLength(LinkStack s)
{
	//计数器
	int count = 0;
	//遍历链栈
	while (s != NULL)
	{
		count++;
		s = s->next;
	}
	return count;
}

//入栈
Status LinkPush(LinkStack* s, ElemType e)
{
	//创建新结点
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	//检查内存是否分配成功
	if (p == NULL)
	{
		return OVERFLOW;
	}
	p->data = e;
	//将新结点插入链栈顶
	p->next = *s;
	*s = p;
	return OK;
}

//出栈
Status LinkPop(LinkStack* s, ElemType* e)
{
	//检查链栈是否为空
	if (*s == NULL)
	{
		return ERROR;
	}
	//保存栈顶元素
	*e = (*s)->data;
	//删除栈顶结点
	StackNode* p = *s;
	*s = (*s)->next;
	free(p);
	return OK;
}

//获取栈顶元素
Status GetLinkTop(LinkStack s, ElemType* e)
{
	//检查链栈是否为空
	if (s == NULL)
	{
		return ERROR;
	}
	*e = s->data;
	return OK;
}

//遍历链栈
void TraverseLinkStack(LinkStack s)
{
	if (s == NULL)
	{
		printf("链栈为空！\n");
		return;
	}
	printf("链栈元素：");
	StackNode* p = s;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//销毁链栈
void DestroyLinkStack(LinkStack* s)
{
	StackNode* p, * q;
	p = *s;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*s = NULL;
}

//测试链栈
int main()
{
	LinkStack s;
	ElemType e;

	//初始化链栈
	InitLinkStack(&s);
	printf("链栈初始化成功！\n");
	printf("======================================\n");

	//入栈
	LinkPush(&s, 10);
	LinkPush(&s, 20);
	LinkPush(&s, 30);
	LinkPush(&s, 40);
	LinkPush(&s, 50);
	printf("入栈成功！\n");
	printf("======================================\n");

	//遍历链栈
	printf("当前链栈元素：\n");
	TraverseLinkStack(s);
	printf("======================================\n");

	//获取栈顶元素
	GetLinkTop(s, &e);
	printf("当前栈顶元素：%d\n", e);
	printf("======================================\n");

	//出栈
	if (LinkPop(&s, &e) == OK)
	{
		printf("出栈成功！出栈元素：%d\n", e);
	}
	else
	{
		printf("出栈失败！链栈为空！\n");
	}
	TraverseLinkStack(s);

	//长度
	printf("当前链栈长度：%d\n", StackLength(s));
	printf("======================================\n");
	if (LinkPop(&s, &e) == OK)
	{
		printf("出栈成功！出栈元素：%d\n", e);
	}
	else
	{
		printf("出栈失败！链栈为空！\n");
	}
	TraverseLinkStack(s);

	//长度
	printf("当前链栈长度：%d\n", StackLength(s));
	printf("======================================\n");

	//再入栈
	LinkPush(&s, 60);
	LinkPush(&s, 70);
	printf("再入栈成功！\n");
	TraverseLinkStack(s);
	//长度
	printf("当前链栈长度：%d\n", StackLength(s));
	printf("======================================\n");

	//再取栈顶
	GetLinkTop(s, &e);
	printf("当前栈顶元素：%d\n", e);
	printf("======================================\n");

	//销毁链栈
	DestroyLinkStack(&s);
	printf("链栈销毁成功！\n");
}