#define _CRT_SECURE_NO_WARNINGS
//#define PI (3.14159)
#include <stdio.h>
//#include <math.h>
//#include <limits.h>
//#include <stdbool.h>




int main()
{
char operator = ' ';
	const char operators[4] = { '+','-','*','/' };
	double operand_1 = 0;
	double operand_2 = 0;
	
	//while (1) {
		printf("Please enter first operand: ");
		scanf(" %lf", &operand_1);
		printf("\nPlease enter second operand: ");
		scanf(" %lf", &operand_2);
		printf("\nPlease enter operator [+,-,*,/]: ");
		scanf(" %c", &operator);
		
		switch (operator)
		{
		case '+':
			printf("\n%.2f %c %.2f = %.2f\n\n", operand_1, operator, operand_2, operand_1 + operand_2);
			break;

		case '-':
			printf("\n%.2f %c %.2f = %.2f\n\n", operand_1, operator, operand_2, operand_1 - operand_2);
			break;

		case '*':
			printf("\n%.2f %c %.2f = %.2f\n\n", operand_1, operator, operand_2, operand_1 * operand_2);
			break;

		case '/':
			printf("\n%.2f %c %.2f = %.2f\n\n", operand_1, operator, operand_2, operand_1 / operand_2);
			break;

		default:
			printf("\nOperand or operator was invalid!\n\n");
			break;
		}
	//}
	
	return 0;
}

