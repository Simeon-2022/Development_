#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions_23.h"

void my_list_init(my_list** obj) {

	*obj = (my_list*)malloc(sizeof(my_list));
	if (*obj == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	(*obj)->char_Arr = (char*)malloc(sizeof(char));

	if ((*obj)->char_Arr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	(*obj)->char_Arr[0] = '\0';
	(*obj)->next = NULL;
}

void my_list_init_defaultValue_(my_list** obj, char* default_value) {

	*obj = (my_list*)malloc(sizeof(my_list));
	if (*obj == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	(*obj)->char_Arr = (char*)calloc(strlen(default_value) + 1,sizeof(char));

	if ((*obj)->char_Arr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strcpy((*obj)->char_Arr, default_value);
	(*obj)->next = NULL;
}

_Bool my_list_empty(my_list* head) {

	return (head == NULL);
}

void my_list_clear(my_list* obj) {

	my_list* current = obj;
	my_list* next = NULL;
	while (current != NULL)
	{
		next = current->next;

		free(current->char_Arr);
		current->char_Arr = NULL;

		free(current);
		current = next;
	}
}

void printNode(const my_list* obj) {

	while (obj != NULL)
	{
		printf("%s\n", obj->char_Arr);
		obj = obj->next;
	}

}

void my_list_push_back(char* data, my_list** obj) {

	my_list* newNode = (my_list*)malloc(sizeof(my_list));
	if (newNode == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	newNode->char_Arr = (char*)malloc(sizeof(char) * strlen(data) + 1);

	if (newNode->char_Arr == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	newNode->next = NULL;

	strcpy(newNode->char_Arr, data);

	if (my_list_empty(*obj))
	{
		*obj = newNode;
		return;
	}

	my_list* tempNode = *obj;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = newNode;
}

void my_list_push_front(char* data, my_list** obj) {

	my_list* newNode = (my_list*)malloc(sizeof(my_list));
	if (newNode == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	newNode->char_Arr = (char*)malloc(sizeof(char) * strlen(data) + 1);

	if (newNode->char_Arr == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strcpy(newNode->char_Arr, data);

	if (my_list_empty(*obj))
	{
		newNode->next = NULL;
		*obj = newNode;
		return;
	}

	newNode->next = *obj;
	*obj = newNode;
}

void my_list_insert(char* data, my_list** obj, size_t pos) {

	my_list* newNode = (my_list*)malloc(sizeof(my_list));
	if (newNode == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	newNode->char_Arr = (char*)malloc(sizeof(char) * strlen(data) + 1);

	if (newNode->char_Arr == NULL) {
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	newNode->next = NULL;

	strcpy(newNode->char_Arr, data);

	if (my_list_empty(*obj))
	{
		*obj = newNode;
		return;
	}

	if (pos == 0)
	{
		newNode->next = *obj;
		*obj = newNode;
		return;
	}

	my_list* current = *obj;

	for (int i = 0; i < pos - 1; i++)
	{
		if (current->next == NULL)
		{
			break;
		}
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;


}

void my_list_pop_back_v_1_(my_list** obj) {


	if (my_list_empty(*obj))
	{
		return;
	}

	int counter = 0;

	my_list* count_Obj_elements = *obj;
	my_list* last_Obj_element = *obj;

	while (count_Obj_elements->next != NULL)
	{
		counter++;
		count_Obj_elements = count_Obj_elements->next;
	}

	if (!counter)
	{
		*obj = NULL;
		free(count_Obj_elements->char_Arr);
		free(count_Obj_elements);

		count_Obj_elements->char_Arr = NULL;
		count_Obj_elements = NULL;
		last_Obj_element->char_Arr = NULL;
		last_Obj_element = NULL;

		return;
	}

	for (int i = 0; i < counter - 1; i++)
	{
		last_Obj_element = last_Obj_element->next;
	}

	last_Obj_element->next = NULL;

	free(count_Obj_elements->char_Arr);
	free(count_Obj_elements);

	count_Obj_elements->char_Arr = NULL;
	count_Obj_elements = NULL;
};

void my_list_pop_back_v_2_(my_list** head) {
	if (*head == NULL)
	{
		return;
	}

	my_list* currentElement = *head;
	my_list* previousElement = NULL;

	while (currentElement->next != NULL)
	{
		previousElement = currentElement;
		currentElement = currentElement->next;
	}

	if (previousElement != NULL) {
		previousElement->next = NULL;
	}
	else
	{
		*head = NULL;
	}

	free(currentElement->char_Arr);
	free(currentElement);
}

void my_list_pop_front(my_list** obj) {

	if (*obj == NULL)
	{
		return;
	}

	my_list* current = *obj;

	*obj = (*obj)->next;

	free(current->char_Arr);
	free(current);
	current->char_Arr = NULL;
	current = NULL;
};

void my_list_erase(my_list** obj, size_t pos) {

	if (*obj == NULL)
	{
		return;
	}

	my_list* currentElement = *obj;
	my_list* previousElement = NULL;

	for (int i = 0; i < pos - 1; i++)
	{
		if (currentElement->next == NULL)
		{
			break;
		}
		previousElement = currentElement;
		currentElement = currentElement->next;
	}


	if (previousElement != NULL && currentElement->next != NULL) {
		previousElement->next = currentElement->next;
	}
	else if (previousElement != NULL && currentElement->next == NULL)
	{
		previousElement->next = NULL;
	}
	else if (previousElement == NULL && currentElement->next != NULL)
	{
		*obj = currentElement->next;
	}
	else
	{
		*obj = NULL;
	}

	free(currentElement->char_Arr);
	free(currentElement);



}

void my_list_erase_v_2_(my_list** obj, size_t pos) {


	if (*obj == NULL) {
		return;
	}

	my_list* current = *obj;
	my_list* prev = NULL;
	size_t index = 0;

	while (current != NULL && index < pos) {
		prev = current;
		current = current->next;
		index++;
	}

	if (current == NULL) {
		return;
	}

	if (prev == NULL) {
		*obj = current->next;
	}
	else {
		prev->next = current->next;
	}

	free(current->char_Arr);
	free(current);
}

void my_list_resize(my_list** obj, size_t elementsCount) {

	bool isNull = false;

	if (my_list_empty(*obj) && elementsCount == 0)
	{
		return;
	}
	else if (my_list_empty(*obj))
	{
		my_list_init(obj);
	}

	my_list* currentElement = *obj;
	my_list* previousElement = NULL;

	int i = 0;
	for (; i < elementsCount; i++)
	{
		if (currentElement == NULL || currentElement->next == NULL)
		{
			isNull = true;
			break;
		}
		previousElement = currentElement;
		currentElement = currentElement->next;
	}

	if (isNull && (i < elementsCount)) // to do check if i < elementsCount
	{
		while (i < elementsCount - 1)
		{
			/*= (my_list*)malloc(sizeof(my_list));
			if (newNode == NULL) {
				printf("Error allocating memory. File validation process failure\n");
				exit(1);
			}

			newNode->char_Arr = (char*)malloc(sizeof(char));
			if (newNode->char_Arr == NULL) {
				printf("Error allocating memory. File validation process failure\n");
				exit(1);
			}

			newNode->char_Arr[0] = '\0';
			newNode->next = NULL;*/
			my_list* newNode = NULL;
			my_list_init(&newNode);

			currentElement->next = newNode;
			currentElement = currentElement->next;

			i++;
		}
	}
	else if (!isNull && (i == elementsCount))
	{
		while (currentElement != NULL)
		{
			my_list* current = currentElement;

			currentElement = currentElement->next;

			free(current->char_Arr);
			free(current);
			current->char_Arr = NULL;
			current = NULL;
		}
		if (previousElement != NULL)
		{
			previousElement->next = NULL;
		}
		else
		{
			(*obj)->next = NULL;
			*obj = NULL;
		}
	}
}

void my_list_resize_init(my_list** obj, size_t elementsCount, char* defaultValue) {

	bool isNull = false;

	if (my_list_empty(*obj) && elementsCount == 0)
	{
		return;
	}
	else if (my_list_empty(*obj))
	{
		my_list_init_defaultValue_(obj, defaultValue);
	}

	my_list* currentElement = *obj;
	my_list* previousElement = NULL;

	int i = 0;
	for (; i < elementsCount; i++)
	{
		if (currentElement == NULL || currentElement->next == NULL)
		{
			isNull = true;
			break;
		}
		previousElement = currentElement;
		currentElement = currentElement->next;
	}

	if (isNull && (i < elementsCount)) // to do check if i < elementsCount
	{
		while (i < elementsCount - 1)
		{
			/*= (my_list*)malloc(sizeof(my_list));
			if (newNode == NULL) {
				printf("Error allocating memory. File validation process failure\n");
				exit(1);
			}

			newNode->char_Arr = (char*)malloc(sizeof(char));
			if (newNode->char_Arr == NULL) {
				printf("Error allocating memory. File validation process failure\n");
				exit(1);
			}

			newNode->char_Arr[0] = '\0';
			newNode->next = NULL;*/
			my_list* newNode = NULL;
			my_list_init_defaultValue_(&newNode, defaultValue);
			currentElement->next = newNode;
			currentElement = currentElement->next;

			i++;
		}
	}
	else if (!isNull && (i == elementsCount))
	{
		while (currentElement != NULL)
		{
			my_list* current = currentElement;

			currentElement = currentElement->next;

			free(current->char_Arr);
			free(current);
			current->char_Arr = NULL;
			current = NULL;
		}
		if (previousElement != NULL)
		{
			previousElement->next = NULL;
		}
		else
		{
			(*obj)->next = NULL;
			*obj = NULL;
		}
	}
}

_Bool predicateFunc(char* str) {

	if (strlen(str) > 10)
	{
		return 1;
	}
	return 0;
}

size_t my_list_erase_if(my_list** obj, _Bool (*predicateFunc)(char*)) {

	size_t countDeletedNodes = 0;
	my_list* currentElement = *obj;
	my_list* previousElement = NULL;

	while (currentElement != NULL)
	{
		if ((*predicateFunc)(currentElement->char_Arr))
		{
			countDeletedNodes++;

			if (previousElement == NULL)
			{
				*obj = (*obj)->next; // currentElement->next;
			}
			else
			{
				previousElement->next = currentElement->next;
			}

			my_list* tempNode = currentElement;
			currentElement = currentElement->next;

			free(tempNode->char_Arr);
			free(tempNode);

		}
		else
		{
			previousElement = currentElement;
			currentElement = currentElement->next;
		}
	}

	return countDeletedNodes;
}

void iterFunc(char* str) {

	int length = (int)strlen(str);
	for (int i = 0; i < length; i++)
	{
		str[i] = toupper(str[i]);
	}
}

void my_list_iterate(my_list** obj, void (*iterFunc)(char*)) {

	if (*obj == NULL)
	{
		return;
	}

	my_list* currentNode = *obj;

	while (currentNode != NULL)
	{
		(*iterFunc)(currentNode->char_Arr);
		currentNode = currentNode->next;
	}
}
