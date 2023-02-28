#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//链表的定义
//数据端（多个时可以单独定义）+指针端
//数据端
 struct data
{
	char arr[10];
	int abc;
};
 //链表结点
typedef struct _Lnode
{
	struct data data;
	struct _Lnode* nest;

} LNode, * LinkList;
//初始化链表
void InitLL(LinkList* L)//L是二级指针
{
	(*L)->nest = NULL;//头结点置NULL

}
//判断是不是空链表
int ListEmepy(LinkList* L)
{
	if ((*L)->nest)
	{
		return 1;
	}
	else
		return 0;
}
//链表的销毁
//p指向L，L指向下一个节点，释放p
void DestroyList(LinkList& L)
{
	LinkList p = L;
	while (L)
	{
		p = L;
		L = L->nest;
		delete p;
	}
}
//链表的清空
int Clearlist(LinkList& L)
{
	LNode* p ,* q;
	p = L->nest;
	while (p)
	{
		q = p->nest ;
		delete p;
		p = q;
	}
	L->nest = NULL;//头指针为NULL
	return 1;
}
//求链表的表长
int ListLength(LinkList L)
{
	int i = 0;
	LNode* p = L->nest;
	while (p)
	{
		i++;
		p = p->nest;
	}
	return i;
}
//取值 取出第i个元素
int GetElem(LinkList L)
{
	LNode* p;
	int i = 0;
	scanf("%d", &i);
	int j = 1;
	p = L->nest;
	
	while (p&&j<i)
	{
		p = p->nest;
		j++;
	}
	if (!p||j > i)
		printf("错误\n");
	int e = p->data.abc ;//定义的data是结构体
	return e;
}
//查找--返回地址 失败返回NULL  O(n)
LNode* LocateElem(LinkList L)
{
	LNode* p;
	int i = 0;
	scanf("%d", &i);
	p = L->nest;
	
	while (p&&p->data .abc !=i)
		p = p->nest;
	return p;
}
//查找==返回第几个结点  O(n)
int LocateElem2(LinkList L)
{
	LNode* p;
	int i = 0;
	scanf("%d", &i);
	p = L->nest;
	int j = 1;
	while (p && p->data.abc != i)
	{
		p = p->nest;
		j++;
	}
	if (p)
		return j ;
	else
		return 0;
}
//插入
//1.先把新的结点的指针域赋成p的后继
//2.再把p的指针域赋成新的结点的数据域
#include<stdlib.h>
void ListInsert(LinkList& L)  //O(1)
{
	//找第i-1个结点
	LNode* p;
	int i = 0;
	scanf("%d", &i);
	p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->nest;
		j++;
	}
	if (!p || j > i - 1)
		printf("错误\n");
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->nest = p->nest;
	p->nest = s;

}
//删除---i-1的指针域保存i+1的地址  O(1)
void ListDelete (LinkList& L ,int&e)
{
	LNode* p ;
	int i = 0;
	scanf("%d", &i);
	p = L;
	int j = 0;
	while (p->nest  && j < i - 1)
	{
		p = p->nest;
		j++;
	}
	if (!(p->nest)|| j > i - 1)
		printf("错误\n");
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s = p->nest;
	p->nest = s->nest;
	int e = (int)s->data.abc ;
	delete s;

}
//头插法
//1.先插入结点
//2.把头节点和链表接上
void CreateList_H(LinkList& L, int i)
{
	L = new LNode;
	L->nest = NULL;
	int n = 0;
	
	for (n = 0; n<i; n++)//O(n)
	{
		LNode* p =(LNode*)malloc(sizeof(LNode)) ;//生成新节点
		scanf("%d", &(p->data.abc));//给新节点的数据域赋值
		p->nest = L->nest;//插入（头结点没接上）
		L->nest = p;//头结点接上链表
	}

}
//尾插法
void CreateList_R(LinkList& L, int i)//O(n)
{
	L = new LNode;
	L->nest = NULL;
	LNode* r = L;//尾指针
	for (int n = 0; n < i; n++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));//生成新节点
		scanf("%d", &(p->data.abc));//给新节点的数据域赋值
		p->nest = NULL;//尾结点
		r->nest = p;//插入尾结点
		r = p;//改变为指针 使得指向尾结点
	}
}
