//普通二叉树
#include <stdio.h>
#include <stdlib.h>

//数据类型
typedef char ElemType;

//二叉树结点结构体
typedef struct BiTNode
{
	ElemType data;                //数据域
	struct BiTNode* lchild;       //左孩子
	struct BiTNode* rchild;       //右孩子
}BiTNode,  * BiTree;

//创建二叉树
void CreateBiTree(BiTree* T)
{
	char ch;
	scanf_s(" %c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);  //创建左子树
		CreateBiTree(&(*T)->rchild);  //创建右子树
	}
}

//前序遍历二叉树
void PreOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);    //访问根结点
		PreOrder(T->lchild);       //前序遍历左子树
		PreOrder(T->rchild);       //前序遍历右子树
	}
}

//中序遍历二叉树
void InOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		InOrder(T->lchild);       //中序遍历左子树
		printf("%c ", T->data);   //访问根结点
		InOrder(T->rchild);       //中序遍历右子树
	}
}

//后序遍历二叉树
void PostOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		PostOrder(T->lchild);      //后序遍历左子树
		PostOrder(T->rchild);      //后序遍历右子树
		printf("%c ", T->data);   //访问根结点
	}
}

// 统计二叉树结点个数
int CountNodes(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + CountNodes(T->lchild) + CountNodes(T->rchild);
	}
}

//统计叶子节点个数
int CountLeaf(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	//这个结点就是叶子结点
	else if (T->lchild == NULL && T->rchild == NULL)
	{
		return  1;
	}
	//这个结点不是叶子结点
	else
	{
		return CountLeaf(T->lchild) + CountLeaf(T->rchild);
	}
}

//求二叉树深度
int TreeDepth(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	//左子树深度
	int left = TreeDepth(T->lchild);
	//右子树深度
	int right = TreeDepth(T->rchild);
	return (left > right ? left : right) + 1;
}

//销毁二叉树
void DestroyBiTree(BiTree* T)
{
	if (*T == NULL)
	{
		return;
	}
	else
	{
		DestroyBiTree(&(*T)->lchild);
		DestroyBiTree(&(*T)->rchild);
		//释放当前结点
		free(*T);
		//最后将根结点置空
		*T = NULL;
	}
}

//测试二叉树
int main()
{
	//创建二叉树
	BiTree T;
	printf("请输入二叉树的结点值（#表示空结点）：\n");
	CreateBiTree(&T);
	printf("=======================================\n");
	printf("前序遍历二叉树：\n");
	PreOrder(T);
	printf("\n=======================================\n");
	printf("中序遍历二叉树：\n");
	InOrder(T);
	printf("\n=======================================\n");
	printf("后序遍历二叉树：\n");
	PostOrder(T);
	printf("\n=======================================\n");
	
	//统计
	int nodes = CountNodes(T);
	int leafs = CountLeaf(T);
	int depth = TreeDepth(T);
	printf("二叉树结点个数：%d\n", nodes);
	printf("二叉树叶子结点个数：%d\n", leafs);
	printf("二叉树深度：%d\n", depth);
	printf("=======================================\n");

	//销毁二叉树
	DestroyBiTree(&T);
	printf("二叉树已销毁！\n");
	return 0;
}
