#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int capacity = 2;
	int size = 0;
	char* buffer = (char*)calloc(capacity, sizeof(char));
	char c = 0;

	while ((c = getchar()) != EOF)
	{
		buffer[size] = c;

		if (size == (capacity - 1))
		{
			capacity *= 2;
			buffer = (char*)realloc(buffer, capacity * sizeof(char));
			if (buffer == NULL)
			{
				printf("Error allocating memory. File validation process failure\n");
				exit(1);
			}
		}
		size++;
	}
	buffer[size] = '\0';

	printf("You've entered >> %s", buffer);
	free(buffer);
	return 0;
}