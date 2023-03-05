#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define error 0
#define ok 1
#define Empty 10
#define NoEmpty 15
//栈和队列也是线性表---插入和删除只能在端点
//栈：后进先出（Last In Frist Out）--LIFO结构
//在表尾插入和删除
//top表尾（栈顶） base表头（栈底）
//插入（入栈 压栈 PUSH） 删除（出栈，弹出 POP）
typedef struct SqStack
{
	int stacksize;
	int* top;
	int* base;
} SqStack;
//栈满 stacksize=top-base
//栈空top=base

//线性栈
//创建一个栈，初始化
int InitStack(SqStack& S)
{
	//C语言
	//栈里放的是整数，所以是sizeof(int)
	S.base = (int*)malloc(MAXSIZE * sizeof(int));
	//c++
	//new  元素类型[个数]--开辟的是数组
	//S.base = new int[MAXSIZE];
	if (!S.base)
		return error;
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//判断栈是否为空
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return	Empty;
	else
		return NoEmpty;
}
//求栈的长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}
//清空栈（栈保存）
int ClearStack(SqStack &S)//对栈进行了操作，要传地址或引用
{
	if (S.base)
	{
		S.top = S.base;
	}
	return ok;
}
//销毁栈--(栈不保存)
int  DestroyStack(SqStack& S)//对栈进行了操作，要传地址或引用
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
//入栈
int PushStack(SqStack & S, int e)
{
	//栈满--上溢
	if (S.top - S.base == S.stacksize)
		return error;
	*S.top++ = e;
	return ok;
}
//出栈--不删除
int Pop(SqStack& S, int& e)
{
	//栈空--下溢
	if (S.base = S.top)//或者S.stacksize=0;调用判断函数也行
		return error;
	e = *--S.top;
	//先下移，再取值
	//--S.top;
	//e = *S.top;
	return ok;
}
//链式存储栈
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
//LinkStack S2;
//栈顶指向栈底
int InitStack2(LinkStack& S)
{
	S = NULL;
	return ok;
}
//判断是不是空栈
int StackEmpty2(LinkStack S2)
{
	if (S2 == NULL)
		return ok;
	else
		return error;
}
//链栈的插入
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
//链栈的删除
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
//取栈顶元素

int GetTop(LinkStack S2)
{
	if (S2 != NULL)
	{
		return S2->data;
	}
	else
		return error;
}
//栈与递归
//递归：对象部分包括自己，自己给自己定义
//递归程序运行时需要系统提供栈来实现
//递归的时间效率差，但程序简单易懂


//队列：先进先出（First In First Out）---FIFO结构
//队列：插入在表尾，删除在表头
//头删尾插

//队列的定义
#define MAXQSIZE 100
typedef struct SqQueue
{
	int* base;
	int front;//对头
	int rear;//对尾
}SqQueue;
//循环队列--取模运算
// 插入
//Q.base[Q.rear]=x
//Q.rear=(Q.rear+1)%MAXQSIZE
//删除
// x=Q.base[Q.front]
//Q.front=(Q.front+1)%MAXQSIZE
//
//少用一个元素
//队满：尾+1=头 (Q.rear+1)%MAXQSIZE=front
//队空rear=front

//队列的初始化
int InitQueue(SqQueue& Q)
{
	//C语言
	Q.base = (int*)malloc(sizeof(int) * MAXQSIZE);
	//c++
	//Q.base = new int[MAXQSIZE];
	if (Q.base == NULL)
		return error;
	Q.rear = Q.front = 0;
	return ok;
}
//求循环队列的长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//入队
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
//出队
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
//取对头
int GetHead(SqQueue Q)
{
	if (Q.rear != Q.front)
		return Q.base[Q.front];

}
//链式队列
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
//初始化
int InitQueue2(LinkQueue& Q)
{
	Q.front = Q.rear = (Queueptr)malloc(sizeof(int) * MAXQSIZE);
	if (!Q.front)
		return error;
	Q.front->next = NULL;
	return ok;
}
//销毁
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
//入队--尾插法
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
//出队
int DeQueue2(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear)
		return error;
	Queueptr p = (Queueptr)malloc(sizeof(QNode));
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	//头结点下一个是尾结点
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	p = NULL;
	//delete p
	return ok;
}
//取队头元素
int GetHead2(LinkQueue Q, int& e)
{
	if (Q.front == Q.rear)
		return error;
	e = Q.front->next ->data ;
	return ok;
}