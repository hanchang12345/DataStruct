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
//Status free(Triplet* T)   //�����������
//{
//	for (int i = 0; i < 3; i++)
//	{
//		T->e[i] = 0;
//	}
//	return ok;
//}
//Status InitTriplet(Triplet* T, ElemType v0, ElemType v1, ElemType v2)  //��Ԫ�����ʼ��
//{
//	//	if (!T) exit(_CRT_GUARDOVERFLOW);
//	T->e[0] = v0;
//	T->e[1] = v1;
//	T->e[2] = v2;
//	return ok;
//}
//Status DestroyTriplet(Triplet* T)  //��ԭ��������
//{
//	free(T);
//	T = NULL;
//	return ok;
//}
//Status Get(Triplet* T, int i, ElemType* e)    //�õ�λ��i������ֵ
//{
//	if (i < 0 || i>3)
//		return ERROR;
//	e = T->e[i - 1];
//	return e;
//}
//Status Put(Triplet* T, int i, ElemType e)    //����i��λ�õ�����ֵ��ֵ��e
//{
//	if (i < 0 || i>3)
//		return ERROR;
//	T->e[i - 1] = e;
//	return ok;
//}
//Status IsAscending(Triplet* T)   //�ж������Ƿ���������
//{
//	return ((T->e[0] < T->e[1]) && (T->e[1] < T->e[2]));
//}
//Status IsDescending(Triplet* T)  //�ж��Ƿ�������
//{
//	return ((T->e[0] > T->e[1]) && (T->e[1] > T->e[2]));
//}
//Status Max(Triplet* T, ElemType* e)  //�ҳ���������ֵ
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
//Status Min(Triplet* T, ElemType* e)  //�ҳ��������Сֵ
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
//Status ShowTriplet(Triplet* T)  //��ӡ����
//{
//	printf("��Ԫ���ֵΪ��\n");
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
//	printf("��������Ԫ���ֵ��\n");
//	scanf_s("%d %d %d", &v0, &v1, &v2);
//	getchar();
//	flag = InitTriplet(&T, v0, v1, v2);
//	printf("��ʼ��������flag=%d\n��", flag);
//	printf("��Ԫ��������ֵ�ֱ�Ϊ��%d,%d,%d\n", T.e[0], T.e[1], T.e[2]);
//	ShowTriplet(&T);
//	Put(&T, 2, 5);
//	printf("��ֵ֮�������Ϊ%d %d %d", T.e[0], T.e[1], T.e[2]);
//	e1 = Get(&T, 1, &e);
//	printf("�õ������һ������Ϊ��%d\n", e1);
//	e2 = Max(&T, e);
//	printf("�õ������������Ϊ��%d\n", e2);
//	e3 = Min(&T, e);
//	printf("�õ�������С����Ϊ��%d\n", e3);
//	printf("�ж���Ԫ���Ƿ�Ϊ����%d\n", IsAscending(&T));
//	printf("�ж���Ԫ���Ƿ�Ϊ����%d\n", IsDescending(&T));
//	DestroyTriplet(&T);
//	printf("��Ԫ������Ϊ��%d %d %d", T.e[0], T.e[1], T.e[2]);
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
//            printf("û��ǰһ���һ���ǣ�%c\n",ch + 1);
//        }
//    else if (ch == 'Z')
//    {
//        printf("û�к�һ�ǰһ���ǣ�%c\n", ch - 1);
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