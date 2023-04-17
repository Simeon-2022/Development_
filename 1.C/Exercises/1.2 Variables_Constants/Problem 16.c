#define PI (3.14159)
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

double circle(double r) {
	double area = PI * pow(r,2);https://github.com/Code-Academy-BG/simeon-aleksandrov-C03/blob/main/1.C/1.2.%20Variables_Constants/Problem%2016

	return area;
};

int main()
{
	printf("%.5f\n", circle(1));
	printf("%.5f\n", circle(1.5));
	printf("%.5f", circle(13));
  
  return 0;
  }
