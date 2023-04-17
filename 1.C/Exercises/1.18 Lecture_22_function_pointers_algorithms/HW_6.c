#define _CRT_SECURE_NO_WARNINGS
#define FUNC_NAME_SIZE 6
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "Functions_22.h"

//Çàäà÷à 6 Íàïðàâåòå ìàñèâ îò óêàçàòåëè êúì ôóíêöèè, êîéòî å ñîðòèðàí ïî áúðçèíà íà èçïúëíåíèå íà ôóíêöèèòå.

//TODO rewrite it to work with fnctions with diff prototypes

typedef struct Func_time
{
	int(*func)(int, int);
	double time;
	char *func_names;

}Func_time;

int func_multipl(int arg_1, int arg_2) {
	int d = 0;
	for (int arg_1 = 0; arg_1 < 10000; ++arg_1)
		for (int arg_2 = 0; arg_2 < 10000; ++arg_2)
			d += arg_1 * arg_2;
	return d; }
int func_div(int arg_1, int arg_2) {
	int d = 0;
	for (int arg_1 = 0; arg_1 < 10000; ++arg_1)
		for (int arg_2 = 1; arg_2 < 10000; ++arg_2)
			d += arg_1 / arg_2;
	return d;
}
int func_add(int arg_1, int arg_2) {
	int d = 0;
	for (int arg_1 = 0; arg_1 < 10000; ++arg_1)
		for (int arg_2 = 1; arg_2 < 10000; ++arg_2)
			d += arg_1 + arg_2;
	return d;
}
int func_subtr(int arg_1, int arg_2) {
	int d = 0;
	for (int arg_1 = 0; arg_1 < 10000; ++arg_1)
		for (int arg_2 = 1; arg_2 < 10000; ++arg_2)
			d += arg_1 - arg_2;
	return d;
}

int compare_funct(const void* a, const void* b) {

	const Func_time* ptr_1 = (const Func_time*)a;
	const Func_time* ptr_2 = (const Func_time*)b;
	
	//Alternative:
	//return (ptr_1->time > ptr_2->time) ? 1 : (ptr_1->time < ptr_2->time) ? -1 : 0;
	if (ptr_1->time > ptr_2->time)
	{
		return 1;
	}
	else if (ptr_1->time < ptr_2->time)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}

int main(void) {
	
	char* names[] = { "func_multipl" ,"func_div" ,"func_add" ,"func_subtr" };
	int (*fun_ptr_arr[4])(int arg_1, int arg_2) = { func_multipl ,func_div ,func_add ,func_subtr };
	Func_time time_spend[4];

	for (size_t i = 0; i < 4; i++)
	{
		clock_t begin = clock();

		(*fun_ptr_arr[i])(132999, 12308987);

		clock_t end = clock();

		time_spend[i] = (Func_time){
			.func = fun_ptr_arr[i],
			.time = (double)(end - begin) / CLOCKS_PER_SEC ,
			.func_names = names[i]
		};
	}
	puts("Unsorted:");
	for (size_t i = 0; i < 4; i++) {
		printf("%s -> time: %.3lf\n", time_spend[i].func_names, time_spend[i].time);
	}

	qsort(time_spend, 4, sizeof(Func_time), compare_funct);

	puts("\nSorted:");
	for (size_t i = 0; i < 4; i++) {
		printf("%s -> time: %.3lf\n", time_spend[i].func_names, time_spend[i].time);
	}
	return 0;
}
