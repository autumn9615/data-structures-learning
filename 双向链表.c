//双向链表
#include <stdio.h>
#include <stdlib.h>

//重定义函数返回值
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

//定义节点结构体
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DuLNode, * DuLinkList;

//初始化双向链表
Status InitDuList(DuLinkList* L)
{
	//开辟内存
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if (!*L)
	{
		return ERROR;
	}
	(*L)->data = 0;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return OK;
}

//判断双向链表是否为空
Status ListEmpty(DuLinkList L)
{
	return L->next == NULL;
}

//求双向链表长度
int ListLength(DuLinkList L)
{
	//计数器
	int len = 0;
	//指针p指向第一个结点
	DuLinkList p = L->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//遍历输出双向链表
void ListTraverse(DuLinkList L)
{
	//指针p指向第一个结点
	DuLinkList p = L->next;
	//检查双向链表是否为空
	if (p == NULL)
	{
		printf("双向链表为空！\n");
		return;
	}
	//遍历输出
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//按位取值
Status GetElem(DuLinkList L, int i, ElemType* e)
{
	//检查双向链表是否合法
	if (L == NULL || i <= 0)
	{
		return ERROR;
	}
	//指针p指向第一个结点
	DuLinkList p = L->next;
	//计数器
	int j = 1;
	//遍历寻找第i个结点
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	//检查是否找到第i个结点
	if (p == NULL || j > i)
	{
		return ERROR;
	}
	//将第i个结点的数据赋值给e
	*e = p->data;
	return OK;
}

//按值查找
int LocateElem(DuLinkList L, ElemType e)
{
	//指针p指向第一个结点
	DuLinkList p = L->next;
	//计数器
	int i = 1;
	//遍历寻找值为e的结点
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	//检查是否找到值为e的结点
	if (p != NULL)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

//在第i个位置插入元素e
Status ListInsert(DuLinkList L, int i, ElemType e)
{
	//检查双向链表是否合法
	if (L == NULL || i < 1)
	{
		return ERROR;
	}
	DuLinkList p = L;
	//计数器
	int j = 0;
	//遍历寻找第i-1个结点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	//检查是否找到第i-1个结点
	if (p == NULL || j > i - 1)
	{
		return ERROR;
	}
	//创建新结点s存储元素e
	DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
	if (!s)
	{
		return ERROR;
	}
	s->data = e;
	//插入新结点s
	s->next = p->next;
	if (p->next != NULL)
	{
		p->next->prior = s;
	}
	p->next = s;
	s->prior = p;
	
	return OK;
}

//删除第i个元素
Status ListDelete(DuLinkList L, int i, ElemType* e)
{
	//检查双向链表是否合法
	if (L == NULL || i < 1 || e == NULL)
	{
		return ERROR;
	}
	DuLNode* p = L;
	//计数器
	int j = 0;
	//遍历寻找第i-1个结点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	//检查是否找到第i-1个结点
	if (p == NULL || p->next == NULL)
	{
		return ERROR;
	}
	//要删除的节点q
	DuLNode* q = p->next;
	*e = q->data;
	//删除
	p->next = q->next;
	if (q->next != NULL)
	{
		q->next->prior = p;
	}
	free(q);

	return OK;
}

//清空双向链表
Status ClearDuList(DuLinkList L)
{
	DuLinkList p, q;
	p = L->next;
	//循环清空下一个
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	//将头结点的next指针置空
	L->next = NULL;
	return OK;
}

//销毁双向链表
Status DestroyDuList(DuLinkList* L)
{
	ClearDuList(*L);
	free(*L);
	*L = NULL;
	return OK;
}

//主函数
int main()
{
	DuLinkList L;
	ElemType e;
	//初始化双向链表
	InitDuList(&L);
	printf("双向链表初始化成功!!!\n");
	//插入元素
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 30);
	ListInsert(L, 4, 40);
	ListInsert(L, 5, 50);
	printf("双向链表插入元素成功!!!\n");
	printf("=====================================\n");
	//输出双向链表
	printf("插入后双向链表元素为：\n");
	ListTraverse(L);
	//插入到第3个位置
	ListInsert(L, 3, 91);
	printf("=====================================\n");
	printf("第3个位置插入元素91后双向链表为：\n");
	ListTraverse(L);
	//删除第4个元素
	ListDelete(L, 4, &e);
	printf("=====================================\n");
	printf("删除第4个元素：%d\n", e);
	printf("删除第4个元素后双向链表为：\n");
	ListTraverse(L);
	printf("=====================================\n");
	//查找第3个元素，按位取值
	GetElem(L, 3, &e);
	printf("查找第3个元素\n");
	printf("第3个元素为：%d\n", e);
	printf("=====================================\n");
	//查找第几个元素为40
	printf("查找第几个元素为40\n");
	int pos = LocateElem(L, 40);
	printf("40的位置为：%d\n", pos);
	printf("=====================================\n");
	//清空销毁
	ClearDuList(L);
	DestroyDuList(&L);
	return 0;
}