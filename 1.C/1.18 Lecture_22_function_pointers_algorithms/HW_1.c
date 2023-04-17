#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>


/*Задача 1
Използвайте typedef за да дефинирате алтернативни имена на следните типове:
● Функция, която не приема параметри и връща double
● Функция, която приема два double параметъра и не връща нищо
● Функция, която приема един int параметър и връща указател към функция, която не приема параметри и връща int
● Функция, която взима три указателя към три различни типа функции - същите типове като на по-горните три типа функции (за
които вече имаме алтернативни имена)*/


typedef double func_1;
typedef void func_2;
typedef int (*fp)(void);
typedef fp func_3;
typedef void func_4;


int positive(void) {

	return 1;
}

int negative(void) {

	return -1;
}

func_1 func1(void) {

	double d;
	scanf("\n%lf", &d);
	return d;
};

func_2 func2(double d_1, double d_2) {
	
	printf("\nDouble %.1f\nDouble %.1f", d_1, d_2);
};

func_3 func3(int i) {
	if (i >= 0)
	{
		return &positive;
	}
	else
	{
		return &negative;
	}
}

func_4 func4(func_1 (*fp1)(void), func_2 (*fp2)(double, double), func_3 (*fp3)(int)) {
	
	double d_1;
	double d_2;

	printf("\n%.2lf", (* fp1)());

	printf("\nEnter two double numbers >> ");
	scanf("%lf %lf", &d_1, &d_2);
	(*fp2)(d_1, d_2);

	printf("\n%p", (* fp3)(-3));
}

//int ffff(int i) {
//
//	return i;
//}
//
//int (*pointer)(int i);

int main()
{
	//pointer = &ffff;
	//printf("%d", pointer(3));

	printf("\n%.2f", func1());

	func2(2.3, 2.5);

	printf("\n%p", func3(3));

	func_1(*fp1)(void) = func1;
	func_2(*fp2)(double, double) = func2;
	func_3(*fp3)(int) = func3;

	func4(fp1, fp2, fp3);

	return 0;
}
