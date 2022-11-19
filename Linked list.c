#include "Linked list.h"

/* create a linked list with first value, returns a pointer to its head*/
linked_list* new_linked_list(void * value)
{
	linked_list *tmp =  (linked_list*)malloc(sizeof(linked_list));
	tmp->value = value; tmp->next = NULL;
	return tmp;
}

/* frees all linked list*/
void free_linked_list(linked_list* head)
{
	if(head->next!=NULL)
		free_linked_list(head->next);
	free(head->value);
	free(head);
}

/* prints linked list as hex and in int size*/
void print_linked_list(linked_list* head)
{
	printf("printing linked list as hex:\n");
	while(head->next!=NULL){
		printf("%x\n", *( (int*)head->value ));
		head=head->next;
	}
	printf("%x\n", *( (int*)head->value ));
	printf("--------\n");
}


/* deletes n'th element, if not exists - do nothing*/
void delete_nth_element_linked_list(linked_list *head,int number)
{
	linked_list *former_link=NULL;
	if (number == 0){
		head=head->next;
		free(head->value);
		free(head);
	}
	else{
		while((number>=1)&&(head!=NULL)){
			former_link=head;
			head=head->next;
			number--;
		}
		if((number == 0)&&(head!=NULL)){
			former_link->next = head->next;
			free(head->value);
			free(head);
		}
	}
}

/* add a value to the end of the linked list*/
void add_value_linked_list(linked_list *head,void *value)
{
	linked_list *tmp =  (linked_list*)malloc(sizeof(linked_list));
	while(head->next!=NULL)
		head = head->next;
	tmp->value = value; tmp->next = NULL;
	head->next = tmp;
}

/* return n'th element value, otherwise NULL*/
void* get_nth_value_linked_list(linked_list *head,int number)
{
	while((number!=0)&&(head->next!=NULL)){
		head=head->next;
		number--;
	}
	if(number == 0)
		return head->value;
	return NULL;
}

/* return number of elements*/
int get_length_linked_list(linked_list *head)
{
	int sum = 0;
	while(head->next!=NULL){
		sum++;
		head=head->next;
	}
	return sum+1;
}

/* sorting the list using bubble sort according to the function given, works only on int values. undefined behaviour otherwise*/
void sort_linked_list(linked_list *head,int (* sorting_func)(int,int))
{
	printf("sorting linked list as int...\n");
	int first_loop = get_length_linked_list(head);
	int second_loop;
	linked_list *head_tmp = head;

	if(first_loop>=2){
		while(first_loop!=0){
			head=head_tmp;
			second_loop = 0;
			while(second_loop<first_loop-1){
				if(sorting_func(*((int*)head->value),*((int*)head->next->value))){
					*((int*)head->value) = *((int*)head->value) ^ *((int*)head->next->value);
					*((int*)head->next->value) = *((int*)head->value) ^ *((int*)head->next->value);
					*((int*)head->value) = *((int*)head->value) ^ *((int*)head->next->value);
				}
				head = head->next;
				second_loop++;
			}
			first_loop--;
		}
	}
}










