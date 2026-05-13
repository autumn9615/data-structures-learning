#include <stdio.h>
#include <stdlib.h>

//函数返回值类型定义
//OK=成功，ERROR=失败
#define OK 1
#define ERROR 0
//函数返回值类型定义
typedef int Status;
typedef int ElemType;

//定义单链表的每个节点
typedef struct LNode
{
	//数据域
	ElemType data;
	//指针域，指向下一个节点
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
//L是指向单链表头指针的指针（需要修改头指针的值，所以传地址）
Status InitList(LinkList* L)
{
	//为头指针分配内存
	*L = (LNode*)malloc(sizeof(LNode));
	//如果分配失败
	if (!(*L))
	{
		return ERROR;
	}
	//初始化头节点的指针域为空，是个空链表
	(*L)->next = NULL;
	//返回成功
	return OK;
}

//判断单链表是否为空
//L是链表头指针（不需要修改，所以传值）
Status ListEmpty(LinkList L)
{
	//如果头节点的指针域（下一个节点）为空，说明链表为空
	if (L->next == NULL)
	{
		return OK;
	}
	//否则，链表不为空
	else
	{
		return ERROR;
	}
}

//求单链表的长度
//L是链表头指针（不需要修改，所以传值）
int ListLength(LinkList L)
{
	//定义一个计数器 
	int len = 0;
	//定义一个指针，指向头节点的下一个节点
	LNode* p = L->next;
	//遍历链表，直到指针为空
	while (p != NULL)
	{
		//经过一个节点，计数器加一
		len++;
		//指针指向下一个节点
		p = p->next;
	}
	return len;
}

//按序号查找链表元素
//L是链表头指针，i是位置，e是输出的值（要改变值，传地址）
Status GetElem(LinkList L, int i, ElemType* e)
{
	//记录当前位置
	int j = 1;
	//定义一个指针指向第一个节点
	LNode* p = L->next;
	//遍历链表，直到找到目标位置
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	//检查位置是否合法
	if (p == NULL || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//按值查找链表元素地址
LNode* LocateElem(LinkList L, ElemType e)
{
	//定义一个指针指向头节点
	LNode* p = L->next;
	//遍历链表找到目标元素
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	//找到了返回这个元素
	return p;
}

//按位置插入元素
Status ListInsert(LinkList L, int i, ElemType e)
{
	int j = 0;
	//p指向头结点
	LNode* p = L;
	//寻找第 i-1 个结点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	//位置非法（节点为空或者要找的位置小于一）
	if (p == NULL || i < 1)
	{
		return ERROR;
	}
	//创建新结点
	LNode* s = (LNode*)malloc(sizeof(LNode));
	//分配失败
	if (s == NULL)
	{
		return ERROR;
	}
	s->data = e;
	//插入
	s->next = p->next;
	p->next = s;
	return OK;
}

//按位置删除
Status ListDelete(LinkList L, int i, ElemType* e)
{
	int j = 0;
	//定义一个指针指向头节点
	LNode* p = L;
	//定义一个临时指针保存删除的节点
	LNode* q;
	//检查p是否为空
	if (p == NULL)
	{
		return ERROR;
	}
	//要找的位置小于一
	if (i < 1)
	{
		return ERROR;
	}
	//找到第i-1个节点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	//位置非法（没有后一个节点了）
	if (p == NULL || p->next == NULL)
	{
		return ERROR;
	}
	//保存删掉的节点
	q = p->next;
	*e = q->data;
	//删除节点q
	p->next = q->next;
	free(q);
	return OK;
}

//遍历输出元素
void TraverseList(LinkList L)
{
	//定义一个指针p指向首元结点
	LNode* p = L->next;
	//检查p是否为空
	if (p == NULL)
	{
		printf("链表为空\n");
		return;
	}
	//遍历链表直到为空
	while (p != NULL)
	{
		printf("%d ", p->data);
		//指针移动到下一个节点
		p = p->next;
	}
	printf("\n");
}

//清空链表
Status ClearList(LinkList L)
{
	//定义一个前指针
	LNode* p;
	//定义一个后指针
	LNode* q;
	//p从第一个节点开始遍历
	p = L->next;
	//循环遍历链表
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

//销毁链表
Status DestroyList(LinkList* L)
{
	//定义一个前指针
	LNode* p;
	//定义一个后指针
	LNode* q;
	//循环遍历链表
	p = (*L)->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;
	return OK;
}

int main()
{
	//定义一个链表
	LinkList L;
	//定义一个变量保存删除的元素的值
	ElemType e;
	//初始化链表
	InitList(&L);
	//插入元素
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 30);
	ListInsert(L, 4, 40);
	ListInsert(L, 5, 50);
	//遍历输出元素
	printf("1.链表元素为：\n");
	printf("链表长度为:%d\n", ListLength(L));
	TraverseList(L);
	printf("===================================\n");
	//删除元素
	ListDelete(L, 3, &e);
	printf("2.删除第3个元素删除元素后链表元素为:\n");
	TraverseList(L);
	printf("链表长度为:%d\n", ListLength(L));
	printf("===================================\n");
	//获取第3个元素的值
	GetElem(L, 3, &e);
	printf("3.第3个元素的值为:%d\n", e);
	printf("===================================\n");
	//按值查找元素
	LNode* p = LocateElem(L, 40);
	if (p != NULL)
	{
		printf("4.按值查找元素40成功，元素地址为:%p\n", p);
	}
	else
	{
		printf("4.按值查找元素40失败，链表中没有这个元素\n");
	}
	printf("===================================\n");
	//清空链表
	ClearList(L);
	printf("5.清空链表后链表元素为: ");
	TraverseList(L);
	printf("===================================\n");
	//销毁链表
	DestroyList(&L);
	printf("6.销毁链表后链表为空\n");
	printf("===================================\n");
	return 0;
}