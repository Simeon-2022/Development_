#define _CRT_SECURE_NO_WARNINGS
#define VECTOR_INIT_CAPACITY 5
#include<stdlib.h>
#include<string.h>
#include "Functions_24.h"

void my_vector_init(vector* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = VECTOR_INIT_CAPACITY;
	vec->data = (vector_data*)malloc(sizeof(vector_data) * vec->capacity);
	if (vec->data == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	vec->data[0] = '\0';
}

void my_vector_init_ptr(vector** vec)
{
	(*vec) = (vector*)malloc(sizeof(vector));
	if (vec == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	(*vec)->capacity = VECTOR_INIT_CAPACITY;
	(*vec)->size = 0;
	(*vec)->data = (vector_data*)malloc(sizeof(vector_data) * (*vec)->capacity); if (vec == NULL)
		if ((*vec)->data == NULL)
		{
			printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}
	(*vec)->data[0] = '\0';
}

_Bool my_vector_empty(vector* vec) {

	return vec->size == 0;
}

_Bool my_vector_empty_ptr(vector** vec) {

	return (*vec)->size == 0;
}

void my_vector_clear(vector* vec) {

	free(vec->data);
	my_vector_init(vec);

}

void my_vector_clear_ptr(vector** vec) {

	free((*vec)->data);
	free(*vec);

	(*vec) = NULL;

	my_vector_init_ptr(vec);
}

size_t my_vector_size(vector* vec) {

	return vec->size;
}

size_t my_vector_size_ptr(vector** vec) {

	return (*vec)->size;
}

void vector_double_capacity(vector* vec) {

	size_t new_capacity = vec->capacity * 2;

	vector_data* new_array = (vector_data*)malloc(sizeof(vector_data) * new_capacity);

	for (size_t i = 0; i <= vec->size; i++)
	{
		new_array[i] = vec->data[i];
	}

	free(vec->data);
	vec->data = new_array;
	vec->capacity = new_capacity;

}

void vector_double_capacity_realloc(vector* vec) {

	size_t new_capacity = vec->capacity * 2;

	vec->data = (vector_data*)realloc(vec->data, new_capacity);

	if (vec->data == NULL)
	{
		fprintf(stderr, "Error allocating memory. File validation process failure\n");
		exit(1);
	}

	vec->capacity = new_capacity;

}

void my_vector_push_back(char* data, vector* vec) {

	size_t dataSize = strlen(data);

	for (size_t i = 0; i < dataSize; i++)
	{
		if (vec->size < vec->capacity)
		{
			vec->data[vec->size++] = data[i];
			vec->size++;
		}
		else
		{
			vector_double_capacity(vec);
			vec->data[vec->size++] = data[i];
			vec->size++;
		}
	}
}

void my_vector_push_back_v2_(char* data, vector* vec) {

	while (vec->size + strlen(data) >= vec->capacity)
	{
		vector_double_capacity_realloc(vec);
	}

	strcat(vec->data, data);
	vec->size += (strlen(data)); // 1 = '\0'
}

void my_vector_insert(char* data, vector* vec, size_t pos) { // pos = index

	while (vec->size + strlen(data) >= vec->capacity)
	{
		vector_double_capacity_realloc(vec);
	}


	if (vec->size >= pos)
	{
		vector_data* new_data = (vector_data*)malloc(sizeof(vector_data) * vec->capacity);
		strcpy(new_data, vec->data + (pos - 1));
		strcpy(vec->data + (pos - 1), data);
		strcat(vec->data, new_data);
		free(new_data);

	}
	else
	{
		strcat(vec->data, data);
	}

	vec->size += (strlen(data)); // 1 = '\0'
};

void my_vector_pop_back(vector* vec) {

	if (vec->size > 0)
	{
		vec->size--;
		vec->data[vec->size] = '\0';
	}
}

void my_vector_erase(vector* vec, size_t pos) {

	size_t index = pos - 1;

	if (vec->size > index && index >= 0)
	{
		strcpy(vec->data + index, vec->data + pos);
	}
	vec->size--;
};

size_t my_vector_capacity(const vector* vec) {

	return vec->capacity;
}

void my_vector_reserve(vector* vec, size_t minCapacity) {

	if (my_vector_capacity(vec) < minCapacity)
	{

		vec->data = (vector_data*)realloc(vec->data, minCapacity);

		if (vec->data == NULL)
		{
			fprintf(stderr, "Error allocating memory. File validation process failure\n");
			exit(1);
		}

		vec->capacity = minCapacity;
	}
};

void my_vector_resize(vector* vec, size_t elementsCount) {

	if (elementsCount <= 0)
	{
		free(vec->data);
		my_vector_init(vec);
		return;
	}

	size_t new_capacity = elementsCount;

	vec->data = (vector_data*)realloc(vec->data, new_capacity);

	if (vec->data == NULL)
	{
		fprintf(stderr, "Error allocating memory. File validation process failure\n");
		exit(1);
	}

	if (vec->size > elementsCount)
	{
		vec->data[elementsCount] = '\0';
	}

	vec->capacity = new_capacity;
	vec->size = elementsCount;
}

void my_vector_resize_init(vector* vec, size_t elementsCount, char* defaultValue) {

	if (elementsCount <= 0)
	{
		free(vec->data);
		my_vector_init(vec);
		return;
	}

	size_t new_capacity = elementsCount;

	vec->data = (vector_data*)realloc(vec->data, new_capacity);

	if (vec->data == NULL)
	{
		fprintf(stderr, "Error allocating memory. File validation process failure\n");
		exit(1);
	}

	if (vec->size < elementsCount)
	{
		for (size_t i = vec->size; i < elementsCount; i++)
		{
			vec->data[i] = *defaultValue;
		}
	}

	vec->data[elementsCount] = '\0';
	vec->capacity = new_capacity;
	vec->size = elementsCount;
}

char* my_vector_front(const vector* vec) {

	return &(*vec->data);

}

char* my_vector_back(const vector* vec) {

	return &(vec->data[vec->size - 1]);
}

char* my_vector_at(const vector* vec, size_t index) {

	return &vec->data[index];
}

void iterFunc(char* ch) {

	*ch = toupper(*ch);
}

void my_vector_iterate(vector* vec, void (*iterFunc)(char*)) {

	int length = (int)strlen(vec->data);
	for (int i = 0; i < length; i++)
	{
		(*iterFunc)(&vec->data[i]);
	}

}

int compare_ltr_(const void* a, const void* b) {

	for (const char* ptr_1 = (const char*)a, *ptr_2 = (const char*)b; *ptr_1 != '\0' || *ptr_2 != '\0';)
	{
		if (*ptr_1 > *ptr_2)
		{
			return 1;
		}
		else if (*ptr_1 < *ptr_2)
		{
			return -1;
		}

		if (*ptr_1 != '\0')
		{
			ptr_1++;
		}
		if (*ptr_2 != '\0')
		{
			ptr_2++;
		}
	}
	return 0;
}

void my_vector_sort(vector* vec, int (*compare_ltr_)(const void* a, const void* b)) {
	int arr_size = (int)strlen(vec->data);

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{
			if ((*compare_ltr_)(&vec->data[j], &vec->data[j + 1]) > 0)
			{
				char temp = vec->data[j];
				vec->data[j] = vec->data[j + 1];
				vec->data[j + 1] = temp;
			}
		}
	}
}
