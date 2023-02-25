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
	C->imag = (b.imag * a.real - b.real * a.imag) / (a.real * a.real + a.imag * a.imag);
}
int main()
{
	complex z1, z2, z3, z4, z;
	assign(&z1, 8.0, 6.0);
	assign(&z2, 4.0, 3.0);
	add(&z3, z1, z2);
	mul(&z4, z1, z2);
	div(&z, z3, z4);
	return 0;
}