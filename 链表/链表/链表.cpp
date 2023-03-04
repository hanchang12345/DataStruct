#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define error 0
#define ok 1
//����Ķ���
//���ݶˣ����ʱ���Ե������壩+ָ���
//���ݶ�
 struct data
{
	char arr[10];
	int abc;
};
 //������
typedef struct _Lnode
{
	struct data data;
	struct _Lnode* nest;

} LNode, * LinkList;
//��ʼ������
void InitLL(LinkList* L)//L�Ƕ���ָ��
{
	(*L)->nest = NULL;//ͷ�����NULL

}
//�ж��ǲ��ǿ�����
int ListEmepy(LinkList* L)
{
	if ((*L)->nest)
	{
		return 1;
	}
	else
		return 0;
}
//���������
//pָ��L��Lָ����һ���ڵ㣬�ͷ�p
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
//��������
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
	L->nest = NULL;//ͷָ��ΪNULL
	return 1;
}
//������ı�
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
//ȡֵ ȡ����i��Ԫ��
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
		printf("����\n");
	 e = p->data.abc ;//�����data�ǽṹ��
	return e;
}
//����--���ص�ַ ʧ�ܷ���NULL  O(n)
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
//����==���صڼ������  O(n)
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
//����
//1.�Ȱ��µĽ���ָ���򸳳�p�ĺ��
//2.�ٰ�p��ָ���򸳳��µĽ���������
#include<stdlib.h>
void ListInsert(LinkList& L,int i,int e)  //O(1)
{
	//�ҵ�i-1�����
	LNode* p;
	
	p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->nest;
		j++;
	}
	if (!p || j > i - 1)
		printf("����\n");
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->nest = p->nest;
	p->nest = s;
	s->data.abc = e;

}
//ɾ��---i-1��ָ���򱣴�i+1�ĵ�ַ  O(1)
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
		printf("����\n");
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s = p->nest;
	p->nest = s->nest;
	int e = (int)s->data.abc ;
	delete s;

}
//ͷ�巨
//1.�Ȳ�����
//2.��ͷ�ڵ���������
void CreateList_H(LinkList& L, int i)
{
	L = new LNode;
	L->nest = NULL;
	int n = 0;
	
	for (n = 0; n<i; n++)//O(n)
	{
		LNode* p =(LNode*)malloc(sizeof(LNode)) ;//�����½ڵ�
		scanf("%d", &(p->data.abc));//���½ڵ��������ֵ
		p->nest = L->nest;//���루ͷ���û���ϣ�
		L->nest = p;//ͷ����������
	}

}
//β�巨
void CreateList_R(LinkList& L, int i)//O(n)
{
	L = new LNode;
	L->nest = NULL;
	LNode* r = L;//βָ��
	for (int n = 0; n < i; n++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d", &(p->data.abc));//���½ڵ��������ֵ
		p->nest = NULL;//β���
		r->nest = p;//����β���
		r = p;//�ı�Ϊָ�� ʹ��ָ��β���
	}
}
//ѭ����������ӱ�ͷ��βָ��O(n)
//��βָ����O(1)
//Ta Tb�Ƿǿյĵ�ѭ������
//��ѭ������ϲ���ѭ������
LinkList Connect(LinkList Ta, LinkList Tb)//O��1��
{
	LinkList p = Ta->nest;//p��Ta��ͷ���
	Ta->nest = Tb->nest->nest;//Ta��β��Tb��ͷ
	delete Tb->nest;//�ͷŵ�Tb��ͷ���
	Tb->nest = p;//Tb�ı�β��Ta�ı�ͷ--ʵ��ѭ��
	return Tb;//����Tbָ�루βָ�룩
}
//˫������
//ǰһ�����ĵ�ַ
//����
//��һ�����ĵ�ַ
typedef struct DuLNode 
{
	struct data data;
	struct DuLNode* next ,*prior;
}DuLNode,*DuLinkList;

//˫������Ĳ���O(n)
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
//˫�������ɾ��O(n)
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
//���Ա�ĺϲ�
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
//��������ĺϲ�
//1.
void Merge_LinkedList(LinkList* La, LinkList* Lb, LinkList* Lc) {
	*Lc = *La; //��Lcʹ��La��ͷ�ڵ���кϲ�
	LinkList pa = (*La)->nest, pb = (*Lb)->nest; 
	// pa, pb�ֱ��ʾ�ϲ�ʱ��ָ�ڵ�
	LinkList pc = *Lc; // pc��ʾLc��β�ڵ�
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
	// pc->next����ҪNULL,��Ϊ�ϲ�ʱһ����ʣ��һ���ڵ㣬ֻ��ָ���ʣ�µĽڵ��OK
	free(*Lb);
	*La = *Lb = NULL;
}
//2.��ȷ��
//void MergeList(LinkList La, LinkList Lb, LinkList& Lc)
//{
//	data pa = La->data;
//	data pb = Lb->data;
//	//���
//	int La_len = ListLength(La);
//	int Lb_len = ListLength(Lb);
//	int Lc_len = La_len + Lb_len;
//	//�����һ��Ԫ��
//	int pa_last = La->data.abc  + La_len - 1;
//	int pb_last = Lb->data.abc + Lb_len - 1;
//	//����pc����
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
//	//��Lcָ��pc��
//	Lc = pc;
//}
// 

//���Ա������ϲ�
#define SQLMAXSIZE 100
typedef int SqlElemType;
typedef struct __Sqlist {
	SqlElemType* base;
	int length;
} Sqlist;

void MergeList_Seq(Sqlist* La, Sqlist* Lb, Sqlist* Lc) {
	Lc->length = La->length + Lb->length;
	SqlElemType* pa = La->base, * pa_last = pa + La->length - 1;
	// paָ��La->base���׵�ַ��pa_lastָ��base�����һ��Ԫ�صĵ�ַ������ͬ��
	SqlElemType* pb = Lb->base, * pb_last = pb + Lb->length - 1;
	SqlElemType* pc = Lc->base;
	while (pa <= pa_last && pb <= pb_last) {
		//��pa>pa_lastʱ˵�����м����е�Ԫ���Ѿ�ȫ�����뵽Lc��
		if (*pa < *pb)
			*(pc++) = *(pa++);
		else
			*(pc++) = *(pb++);
	}
	while (pa <= pa_last)
		*(pc++) = *(pa++); //�ж�La��Ԫ���Ƿ�ȫ������Lc�У�����ͬ��
	while (pb <= pb_last)
		*(pc++) = *(pb++);
}

//����ʽ������
typedef struct __PolyNode {
	double coeffcient;
	int exponent;
	__PolyNode* next;
} PolyNode, * Polynomial;

void InitPolynomial(Polynomial* p, int length) {
	*p = (Polynomial)malloc(sizeof(PolyNode)); //�ȳ�ʼ��ͷ�ڵ�
	(*p)->next = NULL;
	printf("Please input the coefficient and exponent:");
	for (int i = 0; i < length; i++) {
		Polynomial pnew = (Polynomial)malloc(sizeof(PolyNode));
		scanf(" %lf", &(pnew->coeffcient));
		scanf(" %d", &(pnew->exponent));
		Polynomial q = (*p)->next; // qΪָ���pew->exponent��Ľڵ�
		Polynomial pre = (*p); // preָ��q��ֱ��ǰ���ڵ�
		while (q && q->exponent < pnew->exponent) { //��1�ε�forѭ������ִ��
			//ֱ���ҵ�һ���ڵ��exponent����pnew->exponent,���û�ҵ�qָ��NULL
			pre = q;
			q = q->next;
		}
		pnew->next = q; //��Ϊq->exponent > pnew->exponent
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