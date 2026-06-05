//中序线索二叉树

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char TElemType;
typedef int Status;
typedef enum
{
	Link, Thread
}PointeRTag;

//线索二叉树的节点
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode* lchild;                    //左孩子
	struct BiThrNode* rchild;                    //右孩子
	PointeRTag LTag;                             //左线索
	PointeRTag RTag;                             //右线索
}BiThrNode, * BiThrTree;

//全局变量，指向当前访问的节点的前驱节点
BiThrTree pre = NULL;

//创建线索二叉树
void CreateBiThrTree(BiThrTree* T)
{
	char ch;
	scanf_s(" %c", &ch, 1);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (*T == NULL)
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		(*T)->LTag = Link;
		(*T)->RTag = Link;
		CreateBiThrTree(&(*T)->lchild);          //创建左子树
		CreateBiThrTree(&(*T)->rchild);          //创建右子树
	}
}

//中序线索化
void InThreading(BiThrTree p)
{
	if (p == NULL)
	{
		return;
	}
	InThreading(p->lchild);                      //线索化左子树
	//线索化当前节点
	if (p->lchild == NULL)
	{
		p->LTag = Thread;                        //左孩子为空，设置左线索
		p->lchild = pre;                         //左孩子指向前驱节点
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->RTag = Thread;                      //前驱节点的右孩子为空，设置右线索
		pre->rchild = p;                         //前驱节点的右孩子指向当前节点
	}
	pre = p;                                     //更新前驱节点
	InThreading(p->rchild);                      //线索化右子树
}

//建立头节点
Status InOrderThreading(BiThrTree* Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (*Thrt == NULL)
	{
		exit(OVERFLOW);
	}
	(*Thrt)->LTag = Link;                        //左指针指向真正的根节点
	(*Thrt)->RTag = Thread;                      //右指针将来指向尾节点
	(*Thrt)->rchild = *Thrt;                     //右指针初始指向自己

	pre = NULL;

	//空树处理
	if (T == NULL)
	{
		(*Thrt)->lchild = *Thrt;
	}
	//非空树处理
	else
	{
		(*Thrt)->lchild = T;                     //左指针指向根节点
		pre = *Thrt;                             //pre指向头节点
		InThreading(T);                          //中序线索化
		//最后一个节点的处理
		pre->rchild = *Thrt;                     //最后一个节点的右孩子指向头节点
		pre->RTag = Thread;                      //最后一个节点的右变为线索 
		(*Thrt)->rchild = pre;                   //头节点的右孩子指向最后一个节点
	}
	return OK;
}

//中序遍历线索二叉树
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType))
{
	BiThrTree p = T->lchild;                     //p指向根节点
	//回到头节点结束
	while (p != T)
	{
		//找到当前节点最左边的节点
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		//访问找到的节点失败
		if (Visit(p->data) == ERROR)              
		{
			return ERROR;
		}
		//如果当前节点右孩子是线索，访问右孩子
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			if (Visit(p->data) == ERROR)
			{
				return ERROR;
			}
		}
		p = p->rchild;                           //转向右子树
	}
	printf("\n");
	return OK;
}

//访问函数
Status PrintfElement(TElemType e)
{
	printf("%c ", e);
	return OK;
}

//主函数
int main()
{
	BiThrTree T;
	BiThrTree Thrt;
	printf("请输入二叉树的节点（#表示空节点）：\n");
	CreateBiThrTree(&T);                         //创建二叉树
	printf("==========================================\n");
	InOrderThreading(&Thrt, T);                  //中序线索化
	printf("中序线索二叉树遍历结果：\n");
	InOrderTraverse_Thr(Thrt, PrintfElement);    //中序遍历线索二叉树
	return 0;
}