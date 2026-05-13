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
}DuLNode, * DLinkList;

//初始化双向链表
Status InitDuList(DLinkList* L)
{
	//开辟内存
	*L = (DLinkList)malloc(sizeof(DuLNode));
	if (!*L)
	{
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return OK;
}

//判断双向链表是否为空
Status ListEmpty(DLinkList L)
{
	return L->next == NULL;
}

//求双向链表长度
int ListLength(DLinkList L)
{
	//计数器
	int len = 0;
	//指针p指向第一个结点
	DLinkList p = L->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//遍历输出双向链表
void ListTraverse(DLinkList L)
{
	//指针p指向第一个结点
	DLinkList p = L->next;
	//检查双向链表是否为空
	if (p == NULL)
	{
		printf("双向链表为空！\n");
		return;
	}
	//遍历输出
	while (p != NULL)
	{
		printf("%d ", L->data);
		p = p->next;
	}
	printf("\n");
}

//按位取值
Status GetElem(DLinkList L, int i, ElemType* e)
{
	//指针p指向第一个结点
	DLinkList p = L->next;
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
int LocateElem(DLinkList L, ElemType e)
{
	//指针p指向第一个结点
	DLinkList p = L->next;
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












































//
//#define OK 1
//#define ERROR 0
//typedef int Status;
//typedef int ElemType;
//
//// 双向链表结点定义
//typedef struct DuLNode {
//    ElemType data;
//    struct DuLNode* prior;
//    struct DuLNode* next;
//} DuLNode, * DuLinkList;
//
//// 1. 初始化
//Status InitDuList(DuLinkList* L) {
//    *L = (DuLNode*)malloc(sizeof(DuLNode));
//    if (!*L) return ERROR;
//    (*L)->prior = NULL;
//    (*L)->next = NULL;
//    return OK;
//}
//
//// 2. 判空
//Status ListEmpty(DuLinkList L) {
//    return L->next == NULL;
//}
//
//// 3. 求长度
//int ListLength(DuLinkList L) {
//    int len = 0;
//    DuLNode* p = L->next;
//    while (p) {
//        len++;
//        p = p->next;
//    }
//    return len;
//}
//
//// 4. 遍历输出
//void ListTraverse(DuLinkList L) {
//    DuLNode* p = L->next;
//    if (!p) {
//        printf("双向链表为空！\n");
//        return;
//    }
//    while (p) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//// 5. 按位取值
//Status GetElem(DuLinkList L, int i, ElemType* e) {
//    DuLNode* p = L->next;
//    int j = 1;
//    while (p && j < i) {
//        p = p->next;
//        j++;
//    }
//    if (!p || j > i) return ERROR;
//    *e = p->data;
//    return OK;
//}
//
//// 6. 按值查找（返回位序，未找到返回0）
//int LocateElem(DuLinkList L, ElemType e) {
//    int i = 1;
//    DuLNode* p = L->next;
//    while (p && p->data != e) {
//        p = p->next;
//        i++;
//    }
//    return p ? i : 0;
//}
//
//// 7. 插入（修正 i<1 检查）
//Status ListInsert(DuLinkList L, int i, ElemType e) {
//    int j = 0;
//    DuLNode* p = L;
//    while (p && j < i - 1) {
//        p = p->next;
//        j++;
//    }
//    if (!p || i < 1) return ERROR;
//
//    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
//    if (!s) return ERROR;
//    s->data = e;
//
//    s->next = p->next;
//    if (p->next)
//        p->next->prior = s;
//    p->next = s;
//    s->prior = p;
//    return OK;
//}
//
//// 8. 删除（增加显式 i<1 判断）
//Status ListDelete(DuLinkList L, int i, ElemType* e) {
//    int j = 0;
//    DuLNode* p = L;
//    while (p->next && j < i - 1) {
//        p = p->next;
//        j++;
//    }
//    if (!(p->next) || i < 1) return ERROR;
//
//    DuLNode* q = p->next;
//    *e = q->data;
//    p->next = q->next;
//    if (q->next)
//        q->next->prior = p;
//    free(q);
//    return OK;
//}
//
//// 9. 清空
//Status ClearDuList(DuLinkList L) {
//    DuLNode* p = L->next, * q;
//    while (p) {
//        q = p->next;
//        free(p);
//        p = q;
//    }
//    L->next = NULL;
//    return OK;
//}
//
//// 10. 销毁
//Status DestroyDuList(DuLinkList* L) {
//    ClearDuList(*L);
//    free(*L);
//    *L = NULL;
//    return OK;
//}
//
//int main() {
//    DuLinkList L;
//    ElemType e;
//    InitDuList(&L);
//
//    ListInsert(L, 1, 10);
//    ListInsert(L, 2, 20);
//    ListInsert(L, 3, 30);
//    printf("初始: "); ListTraverse(L);
//
//    ListInsert(L, 2, 99);
//    printf("第2位插入99: "); ListTraverse(L);
//
//    ListDelete(L, 3, &e);
//    printf("删除第3位(%d): ", e); ListTraverse(L);
//
//    printf("99的位置: %d\n", LocateElem(L, 99));
//
//    ClearDuList(L);
//    DestroyDuList(&L);
//    return 0;
//}