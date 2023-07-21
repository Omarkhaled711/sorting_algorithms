#include "sort.h"

/**
 * swap_node - swaps 2 nodes
 * @a: the first node
 * @b: the second node
 * Return: the smaller node address
*/
listint_t *swap_node(listint_t *a, listint_t *b)
{
	/*listint_t *temp;*/

	if (a == NULL || b == NULL)
		return (b);
	a->next = b->next;
	if (a->next != NULL)
	{
		a->next->prev = a;
	}
	b->prev = a->prev;
	if (b->prev != NULL)
	{
		b->prev->next = b;
	}
	b->next = a;
	a->prev = b;
	return (b);
}
/**
 * insertion_sort_list - sorts a list using insertion sort algorithm
 * @list: the list to sort
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if ((list == NULL || (*list == NULL)))
	{
		return;
	}
	for (i = *list; i != NULL;)
	{
		j = i->prev;
		i = i->next;
		while (j != NULL)
		{
			if (j->next->n < j->n)
			{
				j = swap_node(j, j->next);
				if (j->prev == NULL)
				{
					*list = j;
				}
				j = j->prev;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
	}

}
