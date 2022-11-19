#include <stddef.h>
#include <stdlib.h>
typedef struct linked_list{
	void* value;
	struct linked_list *next;
} linked_list;


linked_list* new_linked_list(void*);
void free_linked_list(linked_list*);
void print_linked_list(linked_list*);
void delete_nth_element_linked_list(linked_list*,int);
void add_value_linked_list(linked_list*,void*);
void* get_nth_value_linked_list(linked_list*,int);
int get_length_linked_list(linked_list*);
void sort_linked_list(linked_list*,int (*)(int,int));
