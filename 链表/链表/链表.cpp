#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define error 0
#define ok 1
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
int GetElem(LinkList L ,int i,int &e)
{
	LNode* p;

	int j = 1;
	p = L->nest;
	
	while (p&&j<i)
	{
		p = p->nest;
		j++;
	}
	if (!p||j > i)
		printf("错误\n");
	 e = p->data.abc ;//定义的data是结构体
	return e;
}
//查找--返回地址 失败返回NULL  O(n)
LNode* LocateElem(LinkList L ,int* e)
{
	LNode* p;
	int i = 0;
	scanf("%d", &i);
	p = L->nest;
	
	while (p&&p->data .abc !=i)
		e = (int*)p->nest;
	return (LNode*)e;
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
void ListInsert(LinkList& L,int i,int e)  //O(1)
{
	//找第i-1个结点
	LNode* p;
	
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
	s->data.abc = e;

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
//循环链表如果从表头找尾指针O(n)
//从尾指针找O(1)
//Ta Tb是非空的单循环链表
//单循环链表合并成循环链表
LinkList Connect(LinkList Ta, LinkList Tb)//O（1）
{
	LinkList p = Ta->nest;//p存Ta的头结点
	Ta->nest = Tb->nest->nest;//Ta表尾连Tb表头
	delete Tb->nest;//释放掉Tb的头结点
	Tb->nest = p;//Tb的表尾连Ta的表头--实现循环
	return Tb;//返回Tb指针（尾指针）
}
//双向链表
//前一个结点的地址
//数据
//下一个结点的地址
typedef struct DuLNode 
{
	struct data data;
	struct DuLNode* next ,*prior;
}DuLNode,*DuLinkList;

//双向链表的插入O(n)
void DuInsert(DuLinkList L, int position, struct data& e) {
	int i = 0;
	DuLinkList p = L;
	while (p->next && i < position - 1) {
		i++;
		p = p->next;
	}
	DuLinkList pnew = (DuLinkList)malloc(sizeof(DuLinkList));
	pnew->data = e;
	pnew->next = p->next;
	pnew->prior = p;
	p->next = pnew;
	p->next->prior = pnew;
}
//双向链表的删除O(n)
void DivDuList(DuLinkList L, int position, struct data& e)
{
	int i = 0;
	DuLinkList p = L;
	while (p->next && i < position - 1) {
		i++;
		p = p->next;
	}
	DuLinkList pfree = p->next;
	pfree->prior->next = pfree->next;
	pfree->next->prior = pfree->prior;
	e = pfree->data;
	free(pfree);
	pfree = NULL;
}
//线性表的合并
void MergeList(LinkList La, LinkList Lb) 
{
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	for (int i = 1; i <= Lb_len; i++)
	{
		int e = 0;
		GetElem(Lb,i,e);
		if (!LocateElem(La, &e))
		{
			ListInsert(La, ++La_len, e);
		}
	}

}
//有序链表的合并
//1.
void Merge_LinkedList(LinkList* La, LinkList* Lb, LinkList* Lc) {
	*Lc = *La; //让Lc使用La的头节点进行合并
	LinkList pa = (*La)->nest, pb = (*Lb)->nest; 
	// pa, pb分别表示合并时所指节点
	LinkList pc = *Lc; // pc表示Lc的尾节点
	while (pa && pb) {
		if (pa->data.abc  < pb->data.abc ) {
			pc->nest = pa;
			pc = pa;
			pa = pa->nest;
		}
		else {
			pc->nest = pb;
			pc = pb;
			pb = pb->nest;
		}
	}
	pc->nest = pa ? pa : pb;
	// pc->next不需要NULL,因为合并时一定会剩下一串节点，只需指向该剩下的节点就OK
	free(*Lb);
	*La = *Lb = NULL;
}
//2.不确定
//void MergeList(LinkList La, LinkList Lb, LinkList& Lc)
//{
//	data pa = La->data;
//	data pb = Lb->data;
//	//求表长
//	int La_len = ListLength(La);
//	int Lb_len = ListLength(Lb);
//	int Lc_len = La_len + Lb_len;
//	//求最后一个元素
//	int pa_last = La->data.abc  + La_len - 1;
//	int pb_last = Lb->data.abc + Lb_len - 1;
//	//创建pc链表
//	LinkList pc = (LinkList)malloc((Lc_len)*sizeof(LinkList));
//	while (pa.abc <= pa_last && pb.abc <= pb_last)
//	{
//		//LinkList pc = (LinkList)malloc(sizeof(LinkList));
//		if (pa.abc < pb.abc)
//		{
//			pc->data = pa;
//			pc++;
//			pa = La->nest->data;
//		}
//		else
//		{
//			pc->data = pb;
//			pc++;
//			pb = Lb->nest->data;
//		}
//	}
//	while (pa.abc <= pa_last)
//	{
//		//LinkList pc = (LinkList)malloc(sizeof(LinkList));
//		pc->data = pa;
//		pa=La->nest->data ;
//	}
//	while (pb.abc <= pb_last)
//	{
//		//LinkList pc = (LinkList)malloc(sizeof(LinkList));
//		pc->data = pb;
//		pb = Lb->nest->data;
//	}
//	//让Lc指向pc表
//	Lc = pc;
//}
// 

//线性表的有序合并
#define SQLMAXSIZE 100
typedef int SqlElemType;
typedef struct __Sqlist {
	SqlElemType* base;
	int length;
} Sqlist;

void MergeList_Seq(Sqlist* La, Sqlist* Lb, Sqlist* Lc) {
	Lc->length = La->length + Lb->length;
	SqlElemType* pa = La->base, * pa_last = pa + La->length - 1;
	// pa指向La->base的首地址，pa_last指向base中最后一个元素的地址，下面同理
	SqlElemType* pb = Lb->base, * pb_last = pb + Lb->length - 1;
	SqlElemType* pc = Lc->base;
	while (pa <= pa_last && pb <= pb_last) {
		//当pa>pa_last时说明，有集合中的元素已经全部加入到Lc中
		if (*pa < *pb)
			*(pc++) = *(pa++);
		else
			*(pc++) = *(pb++);
	}
	while (pa <= pa_last)
		*(pc++) = *(pa++); //判断La的元素是否全部加入Lc中，下面同理
	while (pb <= pb_last)
		*(pc++) = *(pb++);
}

//多项式的运算
typedef struct __PolyNode {
	double coeffcient;
	int exponent;
	__PolyNode* next;
} PolyNode, * Polynomial;

void InitPolynomial(Polynomial* p, int length) {
	*p = (Polynomial)malloc(sizeof(PolyNode)); //先初始化头节点
	(*p)->next = NULL;
	printf("Please input the coefficient and exponent:");
	for (int i = 0; i < length; i++) {
		Polynomial pnew = (Polynomial)malloc(sizeof(PolyNode));
		scanf(" %lf", &(pnew->coeffcient));
		scanf(" %d", &(pnew->exponent));
		Polynomial q = (*p)->next; // q为指向比pew->exponent大的节点
		Polynomial pre = (*p); // pre指向q的直接前驱节点
		while (q && q->exponent < pnew->exponent) { //第1次的for循环不会执行
			//直到找到一个节点的exponent大于pnew->exponent,如果没找到q指向NULL
			pre = q;
			q = q->next;
		}
		pnew->next = q; //因为q->exponent > pnew->exponent
		pre->next = pnew;
	}
}

#include <stdio.h>
#include <stdlib.h>
typedef struct __PolyNode {
	double coeffcient;
	int exponent;
	__PolyNode* next;
} PolyNode, * Polynomial;
void InitPolynomial(Polynomial* p, int length);
void Traverse(Polynomial P);
Polynomial AddPolynomial(Polynomial pa, Polynomial pb);
int main(void) {
	Polynomial p1, p2, p3;
	InitPolynomial(&p1, 3);
	InitPolynomial(&p2, 4);
	p3 = AddPolynomial(p1, p2);
	Traverse(p1);
	system("pause");
	return 0;
}
/*
x^6+2x^2+3x^5
-2x^2+3x^5+2x^6+x^3
---------------------------
intput:
1 6 2 2 3 5
-2 2 3 5 2 6 1 3
----------------------------
output:
(1.0x^3)+(6.0x^5)+(3.0x^6)
*/