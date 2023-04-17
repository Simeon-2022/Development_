#define PI (3.14159)
#include <stdio.h>
#include <math.h>

double circle(double r) {
	double area = PI * pow(r,2);

	return area;
};
double elipse(double a, double b) {
	double area = PI * a * b;

	return area;
};

int main()
{
	
	printf("%.5f\n", elipse(2,2.2));
	printf("%.5f\n", elipse(1.5,2.5));
	printf("%.5f", elipse(13.3, 15));
  
  return 0;
}
