//#include <stdio.h>
//#include <stdlib.h>
//
////定义最大容量（十个 拿来测试 改这一个地方就可以改大小）
//#define MAXSIZE 10
//
////重新定义“int”类型，改这一个地方就可以改所有类型
//typedef int ElementType;
//
////定义顺序表结构体
//typedef struct 
//{
//	//定义数组，存所有元素
//	ElementType data[MAXSIZE];
//	//定义长度，记录现在有几个元素
//	int length;
//}SqList;//顺序表叫做SqList
//
////清空顺序表 （改变值 要传指针）
//void InitList(SqList *L)
//{
//	//把长度定义为0，表示没有元素了
//	L->length = 0;
//}
//
////判断顺序表是否为空
//int IsEmpty(SqList* L)
//{
//	//如果长度为零，说明是空表，返回1；否则返回0
//	if (L->length == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
////判断顺序表是否已经满了
//int IsFull(SqList* L)
//{
//	//如果长度等于最大容量，说明满了，返回1；否则返回0
//	if (L->length == MAXSIZE)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//	//return L->length == MAXSIZE; //简化写法(L->length == MAXSIZE)这个表达式成立就是1，不成立就是0
//}
//
////打印顺序表中的所有元素
//void PrintList(SqList* L)
//{
//	//先判定是不是空的，不是空的才能打印
//	if (IsEmpty(L))
//	{
//		printf("顺序表为空，无可打印元素!\n");
//		return;
//	}
//	printf("顺序表元素：\n");
//	//遍历顺序表，从下标0到Length-1（有效元素）
//	int i = 0;
//	for (i = 0;i < L->length;i++)
//	{
//		//打印元素，data是数组，i是下标
//		printf("%d\n", L->data[i]);
//	}
//}
//
////在顺序表指定位置pos插入元素e
////pos是插入的位置（从1开始），e是插入的元素
////插入成功返回1，失败返回0
//int ListInsert(SqList* L, int pos, ElementType e)
//{
//	//先判断是否满了，满了就不能插入，返回0
//	if(IsFull(L))
//	{
//		printf("插入失败，顺序表已满！\n");
//		return 0;
//	}
//
//	//再判断插入的位置是否合法，不能是负数，也不能比现在的元素个数还大
//	if (pos < 1 || pos > L->length+1)
//	{
//		printf("插入失败，位置非法！\n");
//		return 0;
//	}
//
//	//从最后一个元素开始，都向后挪一位，一直到pos-1位置（防止数据被覆盖）
//	int i = 0;
//	for (i = L->length-1;i >= pos-1;i--)
//	{
//		L->data[i + 1] = L->data[i];
//		//都向后挪一位，下标+1
//	}
//
//	//把新的元素e放到pos位置
//	L->data[pos-1] = e;
//	
//	//元素个数+1
//	L->length++;
//	printf("插入元素%d成功!\n", e);
//	
//	return 1;
//}
//
////删除顺序表指定位置pos的元素
////pos是删除的位置（从1开始），*e是存被删除的元素（要更改数据，传指针）
////删除成功返回1，失败返回0
//int ListDelete(SqList* L, int pos, ElementType* e)
//{
//	//先判断是否是空表，空表不能删除，返回0
//	if (IsEmpty(L))
//	{
//		printf("删除失败，顺序表为空！\n");
//		return 0;
//	}
//
//	//再判断删除的位置是否合法，不能是负的，不能比现在的元素个数还大
//	if (pos < 1 || pos > L->length)
//	{
//		printf("删除失败，位置非法！\n");
//		return 0;
//	}
//
//	//把被删除的元素通过指针返回给主函数
//	*e = L->data[pos - 1];
//
//	//从pos的下一个元素开始，都向前挪一位，覆盖掉被删除的元素
//	int i = 0;
//	for (i = pos; i < L->length; i++)
//	{
//		L->data[i - 1] = L->data[i];
//	}
//
//	//元素个数-1
//	L->length--;
//	printf("删除元素%d成功！\n", *e);
//
//	return 1;
//}
//
////按给的值查找元素，返回位置，第几个元素是它
////e是要查找的元素，找到返回位置，没找到返回-1
//int LocateElem(SqList* L, ElementType e)
//{
//	//遍历顺序表，找到返回位置
//	int i = 0;
//	for (i = 0; i < L->length; i++)
//	{
//		if (L->data[i] == e)
//		{
//			//返回位置，位置从1开始的，所以要+1
//			return i + 1;
//		}
//	}
//
//	//没找到就返回-1
//	return -1;
//}
//
////按给的位置查找元素，返回元素值
////pos是要查找的位置，*e是存查到的元素值，找到返回1，没找到返回0
//int GetElem(SqList* L, int pos, ElementType* e)
//{
//	//判断位置是否合法，不能是负的，不能比现在的元素个数还大
//	if (pos < 1 || pos > L->length)
//	{
//		printf("查找失败，位置非法！\n");
//		return 0;
//	}
//
//	//找到了的话，把元素的通过指针返回给主函数GetElem
//	*e = L->data[pos - 1];
//	return 1;
//}
//
////按给的值查找元素，返回前一个元素值
////e是要查找的元素，*pre_e是存的前一个元素值，找到返回1，没找到返回0
//int PriorElem(SqList* L, ElementType e, ElementType* pre_e)
//{
//	//遍历顺序表，找到元素e
//	int i = 0;
//	for (i = 0; i < L->length; i++)
//	{
//		if (L->data[i] == e)
//		{
//			//如果i是0.说明前面没有元素了，返回0
//			if (i == 0)
//			{
//				printf("没有前一个元素了！\n");
//				return 0;
//			}
//			else
//			{
//				//把前一个元素通过指针返回给主函数PriorElem	
//				*pre_e = L->data[i - 1];
//				return 1;
//			}
//		}
//	}
//	
//	//没找到就返回0
//	return 0;
//}
//
//
//int main()
//{
//	//定义顺序表变量
//	SqList L;
//
//	//初始化顺序表
//	InitList(&L);
//
//	//插入元素
//	ListInsert(&L, 1, 10);
//	ListInsert(&L, 2, 20);
//	ListInsert(&L, 3, 30);
//	ListInsert(&L, 4, 40);
//	ListInsert(&L, 5, 50);
//
//	printf("======================================================\n");
//
//	//打印顺序表
//	PrintList(&L);
//
//	printf("======================================================\n");
//
//	//删除元素
//	ElementType e1;
//	ListDelete(&L, 3, &e1);
//
//	printf("======================================================\n");
//
//	//打印顺序表
//	PrintList(&L);
//
//	printf("======================================================\n");
//
//	//按值查找元素
//	//定义pos存查到的位置
//	int pos = LocateElem(&L, 40);
//	if (pos != -1)
//	{
//		printf("元素40的位置是%d\n", pos);
//	}
//	else
//	{
//		printf("没有找到元素40！\n");
//	}
//
//	printf("======================================================\n");
//
//	//按位置查找元素
//	ElementType e2;
//	if (GetElem(&L, 2, &e2))
//	{
//		printf("位置2的元素是%d\n", e2);
//	}
//	else
//	{
//		printf("没有找到位置2的元素!\n");
//	}
//
//	printf("======================================================\n");
//
//	//插入元素
//	ListInsert(&L, 3, 60);
//
//	printf("======================================================\n");
//
//	//再次打印顺序表
//	PrintList(&L);
//
//	printf("======================================================\n");
//
//	//判断顺序表是否满了
//	if (IsFull(&L))
//	{
//		printf("顺序表已满！\n");
//	}
//	else
//	{
//		printf("顺序表未满！\n");
//	}
//
//	printf("======================================================\n");
//
//	//判断顺序表是否为空
//	if (IsEmpty(&L))
//	{
//		printf("顺序表为空！\n");
//	}
//	else
//	{
//		printf("顺序表不为空！\n");
//	}
//
//	printf("======================================================\n");
//
//	//按值查找元素，返回前一个元素值
//	ElementType pre_e;
//
//	if (PriorElem(&L, 60, &pre_e))
//	{
//		printf("元素60的前一个元素是%d\n", pre_e);
//	}
//	else
//	{
//		printf("没有找到元素60的前一个元素！\n");
//	}
//
//	return 0;
//}