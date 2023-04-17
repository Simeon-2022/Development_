#ifndef FUNCTIONS_24_H
#define FUNCTIONS_24_H
#include <stdio.h>

typedef char vector_data;
typedef struct vector
{
	vector_data* data;
	size_t size;
	size_t capacity;
}vector;

void	my_vector_init					(vector* vec);
void	my_vector_init_ptr				(vector** vec);
_Bool	my_vector_empty					(vector* vec);
_Bool	my_vector_empty_ptr				(vector** vec);
void	my_vector_clear					(vector* vec);
void	my_vector_clear_ptr				(vector** vec);
size_t	my_vector_size					(vector* vec);
size_t	my_vector_size_ptr				(vector** vec);
void	vector_double_capacity			(vector* vec);
void	vector_double_capacity_realloc	(vector* vec);
void	my_vector_push_back				(char* data, vector* vec);
void	my_vector_push_back_v2_			(char* data, vector* vec);
void	my_vector_insert				(char* data, vector* vec, size_t pos);
void	my_vector_pop_back				(vector* vec);
void	my_vector_erase					(vector* vec, size_t pos);
size_t	my_vector_capacity				(const vector* vec);
void	my_vector_reserve				(vector* vec, size_t minCapacity);
void	my_vector_resize				(vector* vec, size_t elementsCount);
void	my_vector_resize_init			(vector* vec, size_t elementsCount, char* defaultValue);
char*	my_vector_front					(const vector* vec);
char*	my_vector_back					(const vector* vec);
char*	my_vector_at					(const vector* vec, size_t index);
void	iterFunc						(char* ch);
void	my_vector_iterate				(vector* vec, void (*iterFunc)(char*));
int		compare_ltr_					(const void* a, const void* b);
void	my_vector_sort					(vector* vec, int (*compare_ltr_)(const void* a, const void* b));


#endif 