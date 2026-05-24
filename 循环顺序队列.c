//循环顺序队列
#include <stdio.h>
#include <stdlib.h>

//重定义函数返回值
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;
#define MAXQSIZE 100

//循环顺序队列结构体
typedef struct
{
	ElemType data[MAXQSIZE];
	int front;   //队头指针
	int rear;    //队尾指针
}SqQueue;

//初始化循环顺序队列
Status InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//判断循环顺序队列是否为空
Status QueueEmpty(SqQueue Q)
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
Status EnQueue(SqQueue* Q, ElemType e)
{
	//判断队列是否已满
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
	{
		return OVERFLOW;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

//出队
Status DeQueue(SqQueue* Q, ElemType* e)
{
	//判断队列是否为空
	if (Q->rear == Q->front)
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

//获取队头元素
Status GetHead(SqQueue Q, ElemType* e)
{
	//判断队列是否为空
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	*e = Q.data[Q.front];
	return OK;
}

//遍历循环顺序队列
void TraverseQueue(SqQueue Q)
{
	//判断队列是否为空
	if (QueueEmpty(Q))
	{
		printf("队列为空！\n");
		return;
	}
	printf("队列元素为：");
	int i = Q.front;
	while (i != Q.rear)
	{
		printf("%d ", Q.data[i]);
		i = (i + 1) % MAXQSIZE;
	}
	printf("\n");
}

int main()
{
	SqQueue Q;
	ElemType e;
	int i;

	//初始化队列
	InitQueue(&Q);
	printf("循环顺序队列已初始化！\n");
	printf("=====================================\n");

	//入队
	EnQueue(&Q, 10);
	EnQueue(&Q, 20);
	EnQueue(&Q, 30);
	EnQueue(&Q, 40);
	EnQueue(&Q, 50);
	printf("入队完成！\n");
	TraverseQueue(Q);
	printf("=====================================\n");

	//取队头元素
	GetHead(Q, &e);
	printf("队头元素为：%d\n", e);
	printf("=====================================\n");

	//出队
	if (DeQueue(&Q, &e) == OK)
	{
		printf("出队元素为：%d\n", e);
	}
	else
	{
		printf("出队失败，队列为空！\n");
	}
	TraverseQueue(Q);
	printf("=====================================\n");

	if ((DeQueue(&Q, &e) == OK))
	{
		printf("出队元素为：%d\n", e);
	}
	else
	{
		printf("出队失败，队列为空！\n");
	}
	TraverseQueue(Q);
	printf("=====================================\n");
	return 0;
}