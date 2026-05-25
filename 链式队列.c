//链式队列
#include <stdio.h>
#include <stdlib.h>

//定义返回值
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;

//定义节点结构体
typedef struct QNode
{
	ElemType data;        //数据域
	struct QNode* next;   //指针域
}QNode, * QNodePtr;

//定义队列结构体
typedef struct
{
	QNodePtr front;       //队头
	QNodePtr rear;        //队尾
}LinkQueue;

//初始化链式队列
Status InitLinkQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));
	if (Q->front == NULL)
	{
		return OVERFLOW;
	}
	Q->front->next = NULL;
	return OK;
}

//判断链式队列是否为空
Status LinkQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//入队
Status EnLinkQueue(LinkQueue* Q, ElemType e)
{
	//创建新节点
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	if (p == NULL)
	{
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	//插入
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//出队
Status DeLinkQueue(LinkQueue* Q, ElemType* e)
{
	//判断队列是否为空
	if (LinkQueueEmpty(*Q))
	{
		return ERROR;
	}
	//删除节点
	QNodePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	//只有一个节点的时候
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

//获取队头元素
Status GetLinkHead(LinkQueue Q, ElemType* e)
{
	//判断队列是否为空
	if (LinkQueueEmpty(Q))
	{
		return ERROR;
	}
	*e = Q.front->next->data;
	return OK;
}

//遍历链式队列
void TraverseLinkQueue(LinkQueue Q)
{
	//判断队列是否为空
	if (LinkQueueEmpty(Q))
	{
		printf("链式队列为空！\n");
		return;
	}
	printf("链式队列的元素为：");
	QNodePtr p = Q.front->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//销毁链式队列
void DestroyLinkQueue(LinkQueue* Q)
{
	QNodePtr p;
	QNodePtr q;
	p = Q->front;
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	Q->front = Q->rear = NULL;
}

//测试
int main()
{
	LinkQueue Q;
	ElemType e;

	//初始化链式队列
	InitLinkQueue(&Q);
	printf("链式队列初始化成功！\n");
	printf("====================================\n");

	//入队
	EnLinkQueue(&Q, 10);
	EnLinkQueue(&Q, 20);
	EnLinkQueue(&Q, 30);
	EnLinkQueue(&Q, 40);
	EnLinkQueue(&Q, 50);
	printf("第一次入队成功！\n");
	TraverseLinkQueue(Q);
	printf("====================================\n");

	//取队头元素
	if (GetLinkHead(Q, &e) == OK)
	{
		printf("队头元素为：%d\n", e);
	}
	printf("====================================\n");

	//第一次出队
	if (DeLinkQueue(&Q, &e) == OK)
	{
		printf("出队元素为：%d\n", e);
	}
	TraverseLinkQueue(Q);
	printf("====================================\n");

	//第二次入队
	EnLinkQueue(&Q, 60);
	EnLinkQueue(&Q, 70);
	printf("第二次入队成功！\n");
	TraverseLinkQueue(Q);
	printf("====================================\n");

	//销毁链式队列
	DestroyLinkQueue(&Q);
	printf("链式队列销毁成功！\n");
}