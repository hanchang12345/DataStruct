#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct complex
{
	float real;
	float imag;
}complex;
void assign(complex* A, float a, float b)
{
	A->real = a;
	A->imag = b;
}
void add(complex* B, complex c, complex d)
{
	B->real = c.real + d.real;
	B->imag = c.imag + d.imag;
}
void mul(complex* C, complex c, complex d)
{
	C->real = (c.real * d.real) - (c.imag * d.imag);
	C->imag = (c.real * d.imag) + (c.imag * d.real);
}
void div(complex* C, complex a, complex b)
{
	C->real = (a.real * b.real + a.imag * b.imag) / (a.real * a.real + a.imag * a.imag);
	C->imag =(b.imag *a.real -b.real *a.imag )/ (a.real * a.real + a.imag * a.imag);
}
int main()
{
	complex z1, z2, z3, z4, z;
	assign(&z1, 8.0, 6.0);
	assign(&z2, 4.0, 3.0);
	add(&z3,z1,z2);
	mul(&z4, z1, z2);
	div(&z, z3, z4);
	return 0;
}
//#define ok 1;
//#define ERROR 0;
//typedef int Status;
//typedef int ElemType;
//
//typedef struct
//{
//	ElemType e[3];
//}Triplet;
//
//Status free(Triplet* T)   //数组内容清空
//{
//	for (int i = 0; i < 3; i++)
//	{
//		T->e[i] = 0;
//	}
//	return ok;
//}
//Status InitTriplet(Triplet* T, ElemType v0, ElemType v1, ElemType v2)  //三元数组初始化
//{
//	//	if (!T) exit(_CRT_GUARDOVERFLOW);
//	T->e[0] = v0;
//	T->e[1] = v1;
//	T->e[2] = v2;
//	return ok;
//}
//Status DestroyTriplet(Triplet* T)  //三原数组销毁
//{
//	free(T);
//	T = NULL;
//	return ok;
//}
//Status Get(Triplet* T, int i, ElemType* e)    //得到位置i的数组值
//{
//	if (i < 0 || i>3)
//		return ERROR;
//	e = T->e[i - 1];
//	return e;
//}
//Status Put(Triplet* T, int i, ElemType e)    //将第i个位置的数组值赋值给e
//{
//	if (i < 0 || i>3)
//		return ERROR;
//	T->e[i - 1] = e;
//	return ok;
//}
//Status IsAscending(Triplet* T)   //判断数组是否升序排列
//{
//	return ((T->e[0] < T->e[1]) && (T->e[1] < T->e[2]));
//}
//Status IsDescending(Triplet* T)  //判断是否降序排列
//{
//	return ((T->e[0] > T->e[1]) && (T->e[1] > T->e[2]));
//}
//Status Max(Triplet* T, ElemType* e)  //找出数组的最大值
//{
//	if (T->e[0] > T->e[1])
//	{
//		if (T->e[0] > T->e[2])
//		{
//			e = T->e[0];
//		}
//		else
//			e = T->e[2];
//	}
//	else
//	{
//		if (T->e[1] > T->e[2])
//		{
//			e = T->e[1];
//		}
//		else
//			e = T->e[2];
//	}
//	return e;
//}
//Status Min(Triplet* T, ElemType* e)  //找出数组的最小值
//{
//	if (T->e[0] < T->e[1])
//	{
//		if (T->e[0] < T->e[2])
//		{
//			e = T->e[0];
//		}
//		else
//			e = T->e[2];
//	}
//	else
//	{
//		if (T->e[1] < T->e[2])
//		{
//			e = T->e[1];
//		}
//		else
//			e = T->e[2];
//	}
//	return e;
//}
//Status ShowTriplet(Triplet* T)  //打印数组
//{
//	printf("三元组的值为：\n");
//	for (int i = 0; i < 3; i++)
//	{
//
//		printf("%d ", T->e[i]);
//	}
//	return ok;
//}
//int main()
//{
//	Triplet T;
//	Status i, flag;
//	ElemType v0, v1, v2, e, e1, e2, e3;
//	printf("请输入三元组的值：\n");
//	scanf_s("%d %d %d", &v0, &v1, &v2);
//	getchar();
//	flag = InitTriplet(&T, v0, v1, v2);
//	printf("初始化函数后，flag=%d\n，", flag);
//	printf("三元组中三个值分别为：%d,%d,%d\n", T.e[0], T.e[1], T.e[2]);
//	ShowTriplet(&T);
//	Put(&T, 2, 5);
//	printf("赋值之后的数组为%d %d %d", T.e[0], T.e[1], T.e[2]);
//	e1 = Get(&T, 1, &e);
//	printf("得到数组第一个数字为：%d\n", e1);
//	e2 = Max(&T, e);
//	printf("得到数组最大数字为：%d\n", e2);
//	e3 = Min(&T, e);
//	printf("得到数组最小数字为：%d\n", e3);
//	printf("判断三元组是否为升序：%d\n", IsAscending(&T));
//	printf("判断三元组是否为降序：%d\n", IsDescending(&T));
//	DestroyTriplet(&T);
//	printf("三元组内容为：%d %d %d", T.e[0], T.e[1], T.e[2]);
//	getchar();
//	return 0;
//
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//int main(int argc,char* argv[])
//{
//	float x, y,a;
//	for (y = 1.5; y > -1.5; y -= 0.1)
//	{
//		for (x = -1.5; x < 1.5; x += 0.05)
//		{
//			a = x * x + y * y - 1;
//			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
//		}
//		system("color 0c");
//		putchar('\n');
//	}
//
//
//	return 0;
//}



//int main()
//{
//	char ch ;
//	ch = 'a+b';
//	return 0;
//}
//#include<stdio.h>
//    int main()
//    {
//        char ch = 0 ;
//        scanf("%c",&ch);
//        if(ch == 'A')
//        {
//            printf("没有前一项，后一项是：%c\n",ch + 1);
//        }
//    else if (ch == 'Z')
//    {
//        printf("没有后一项，前一项是：%c\n", ch - 1);
//    }
//    else
//    {
//        printf("%c%c\n", ch - 1, ch + 1);
//    }
//    return 0;
//    }


//#include<stdio.h>
//int main()
//{
//    char ch = 'B';
//    scanf("%c", &ch);
//    if(ch == 'A')
//    {
//        printf("%c\n",ch + 1);
//    }
//    else if (ch == 'Z')
//    {
//        printf("%c\n", ch - 1);
//    }
//    else
//    {
//        printf("%c%c\n", ch - 1, ch + 1);
//    }
//    if(ch == 0)
//    {
//        printf("%d\n",ch + 1);
//    }
//    else
//    {
//        printf("%d%d\n", ch - 1, ch + 1);
//    }
//    return 0;
//}
// 
// 
//char ch1[] = "The fox says,";
//char ch2[] = "I am sure that these grapes are sour.";
//char ch3[] = '\"';
//printf("%s%c%s%c", ch1, ch3, ch2, ch3);
//return 0;