#include <stdio.h>

int main(){
	
	const float height = 12.5f;
	const float width = 20.6f;
	const float perimeter = 2 * (height + width);
	const float area = height * width;
	printf("Perimeter is: %.2f sq.sm \nArea is: %.2f sq.sm", perimeter, area);
	
	return 0;
}