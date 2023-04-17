#include <stdio.h>
#include <limits.h>

int main(){

double c = 4.9876543;
	printf("%.7f\n", c);

	long double b = 7.123456789012345678890;
	printf("%.21Lf\n", b);

	long double ld = 18398458438583853.28;
	printf("%.2Lf\n", ld);

	long double ld1 = 18398458438583853.39875937284928422;
	printf("%.17Lf\n", ld1);
  
return 0;
}
