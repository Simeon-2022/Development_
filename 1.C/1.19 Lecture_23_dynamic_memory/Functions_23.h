#pragma once
#ifndef FUNCTIONS_23_H
#define FUNCTIONS_23_H

typedef struct node {

	char* char_Arr;//asdasdas
	struct node* next;
}my_list;


_Bool	my_list_empty				(my_list* obj);
void	my_list_init				(my_list** obj);
void	my_list_clear				(my_list* obj);
void	printNode					(const my_list* obj);
void	my_list_push_back			(char* data, my_list** obj);
void	my_list_push_front			(char* data, my_list** obj);
void	my_list_insert				(char* data, my_list** obj, size_t pos);
void	my_list_init_defaultValue_	(my_list** obj, char* default_value);
void	my_list_pop_back_v_1_		(my_list** obj);
void	my_list_pop_back_v_2_		(my_list** head);
void	my_list_pop_front			(my_list** obj);
void	my_list_erase				(my_list** obj, size_t pos);
void	my_list_erase_v_2_			(my_list** obj, size_t pos);
void	my_list_resize				(my_list** obj, size_t elementsCount);
void	my_list_resize_init			(my_list** obj, size_t elementsCount, char* defaultValue);
_Bool	predicateFunc				(char* str);
size_t	my_list_erase_if			(my_list** obj, _Bool (*predicateFunc)(char*));
void	iterFunc					(char* str);
void	my_list_iterate				(my_list** obj, void (*iterFunc)(char*));

#endif // !FUNCTIONS_23_H
