#include "Linked list.h"

int get_bigger(int,int);

void main(void)
{
	int *x = (int*)malloc (sizeof(int));
	int *y = (int*)malloc (sizeof(int));
	int *z = (int*)malloc (sizeof(int));
	int *m = (int*)malloc (sizeof(int));
	*x = 1;
	*y = 'abc';
	*z = 2;
	*m = 'c';
	linked_list *tmp = new_linked_list(x);
	add_value_linked_list(tmp, y);
	add_value_linked_list(tmp, z);
	add_value_linked_list(tmp, m);
	print_linked_list(tmp);
	sort_linked_list(tmp, get_bigger);
	print_linked_list(tmp);

	free_linked_list(tmp);
}


int get_bigger(int x, int y)
{
	return (x>y)? 1:0;
}
