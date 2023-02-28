#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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
		printf("����\n");
	int e = p->data.abc ;//�����data�ǽṹ��
	return e;
}
//����--���ص�ַ ʧ�ܷ���NULL  O(n)
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
void ListInsert(LinkList& L)  //O(1)
{
	//�ҵ�i-1�����
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
		printf("����\n");
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->nest = p->nest;
	p->nest = s;

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
