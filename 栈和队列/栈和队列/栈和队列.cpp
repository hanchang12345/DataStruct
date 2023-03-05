#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define error 0
#define ok 1
#define Empty 10
#define NoEmpty 15
//ջ�Ͷ���Ҳ�����Ա�---�����ɾ��ֻ���ڶ˵�
//ջ������ȳ���Last In Frist Out��--LIFO�ṹ
//�ڱ�β�����ɾ��
//top��β��ջ���� base��ͷ��ջ�ף�
//���루��ջ ѹջ PUSH�� ɾ������ջ������ POP��
typedef struct SqStack
{
	int stacksize;
	int* top;
	int* base;
} SqStack;
//ջ�� stacksize=top-base
//ջ��top=base

//����ջ
//����һ��ջ����ʼ��
int InitStack(SqStack& S)
{
	//C����
	//ջ��ŵ���������������sizeof(int)
	S.base = (int*)malloc(MAXSIZE * sizeof(int));
	//c++
	//new  Ԫ������[����]--���ٵ�������
	//S.base = new int[MAXSIZE];
	if (!S.base)
		return error;
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return	Empty;
	else
		return NoEmpty;
}
//��ջ�ĳ���
int StackLength(SqStack S)
{
	return S.top - S.base;
}
//���ջ��ջ���棩
int ClearStack(SqStack &S)//��ջ�����˲�����Ҫ����ַ������
{
	if (S.base)
	{
		S.top = S.base;
	}
	return ok;
}
//����ջ--(ջ������)
int  DestroyStack(SqStack& S)//��ջ�����˲�����Ҫ����ַ������
{
	if (S.base)
	{
		//c++
		//delete S.base;
		free(S.base);
		S.base = S.top = NULL;
		S.stacksize = 0;
	}
	return ok;
}
//��ջ
int PushStack(SqStack & S, int e)
{
	//ջ��--����
	if (S.top - S.base == S.stacksize)
		return error;
	*S.top++ = e;
	return ok;
}
//��ջ--��ɾ��
int Pop(SqStack& S, int& e)
{
	//ջ��--����
	if (S.base = S.top)//����S.stacksize=0;�����жϺ���Ҳ��
		return error;
	e = *--S.top;
	//�����ƣ���ȡֵ
	//--S.top;
	//e = *S.top;
	return ok;
}
//��ʽ�洢ջ
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
//LinkStack S2;
//ջ��ָ��ջ��
int InitStack2(LinkStack& S)
{
	S = NULL;
	return ok;
}
//�ж��ǲ��ǿ�ջ
int StackEmpty2(LinkStack S2)
{
	if (S2 == NULL)
		return ok;
	else
		return error;
}
//��ջ�Ĳ���
int Push2(LinkStack& S2, int e)
{
	LinkStack p = new StackNode;
	if (!p)
		return error;
	p->data = e;
	p->next = S2;
	S2 = p;
	return ok;
}
//��ջ��ɾ��
int Pop2(LinkStack& S2, int& e)
{
	if (S2 == NULL)
		return error;
	e = S2->data;
	LinkStack p = new StackNode;
	p = S2;
	S2 = S2->next;
	delete p;
	p = NULL;
	return ok;
}
//ȡջ��Ԫ��

int GetTop(LinkStack S2)
{
	if (S2 != NULL)
	{
		return S2->data;
	}
	else
		return error;
}
//ջ��ݹ�
//�ݹ飺���󲿷ְ����Լ����Լ����Լ�����
//�ݹ��������ʱ��Ҫϵͳ�ṩջ��ʵ��
//�ݹ��ʱ��Ч�ʲ��������׶�


//���У��Ƚ��ȳ���First In First Out��---FIFO�ṹ
//���У������ڱ�β��ɾ���ڱ�ͷ
//ͷɾβ��

//���еĶ���
#define MAXQSIZE 100
typedef struct SqQueue
{
	int* base;
	int front;//��ͷ
	int rear;//��β
}SqQueue;
//ѭ������--ȡģ����
// ����
//Q.base[Q.rear]=x
//Q.rear=(Q.rear+1)%MAXQSIZE
//ɾ��
// x=Q.base[Q.front]
//Q.front=(Q.front+1)%MAXQSIZE
//
//����һ��Ԫ��
//������β+1=ͷ (Q.rear+1)%MAXQSIZE=front
//�ӿ�rear=front

//���еĳ�ʼ��
int InitQueue(SqQueue& Q)
{
	//C����
	Q.base = (int*)malloc(sizeof(int) * MAXQSIZE);
	//c++
	//Q.base = new int[MAXQSIZE];
	if (Q.base == NULL)
		return error;
	Q.rear = Q.front = 0;
	return ok;
}
//��ѭ�����еĳ���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//���
int EnQueue(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		return error;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return ok;
}
//����
int DeQueue(SqQueue& Q, int e)
{
	if (Q.rear == Q.front)
	{
		return error;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return ok;
}
//ȡ��ͷ
int GetHead(SqQueue Q)
{
	if (Q.rear != Q.front)
		return Q.base[Q.front];

}
//��ʽ����
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode, * Queueptr;
typedef struct 
{
	Queueptr front;
	Queueptr rear;
} LinkQueue;
//��ʼ��
int InitQueue2(LinkQueue& Q)
{
	Q.front = Q.rear = (Queueptr)malloc(sizeof(int) * MAXQSIZE);
	if (!Q.front)
		return error;
	Q.front->next = NULL;
	return ok;
}
//����
int DestroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		QNode* p = (QNode*)malloc(sizeof(Queueptr));
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return ok;
}
//���--β�巨
int EnQueue2(LinkQueue& Q, int e)
{
	Queueptr p = (Queueptr)malloc(sizeof(QNode));
	if (!p)
	{
		return error;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return ok;
}
//����
int DeQueue2(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear)
		return error;
	Queueptr p = (Queueptr)malloc(sizeof(QNode));
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	//ͷ�����һ����β���
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	p = NULL;
	//delete p
	return ok;
}
//ȡ��ͷԪ��
int GetHead2(LinkQueue Q, int& e)
{
	if (Q.front == Q.rear)
		return error;
	e = Q.front->next ->data ;
	return ok;
}