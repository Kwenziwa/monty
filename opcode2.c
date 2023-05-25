#include "monty.h"

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @dbly: head of the linked list
 * @lnum: line number;
 * Return: no return
 * info:The result is stored in 2nd value node from the top
 * and top value removed.
 */

void _mod(stack_t **dbly, unsigned int lnum)
{
	int k = 0;
	stack_t *ax = NULL;

	ax = *dbly;

	for (; ax != NULL; ax = ax->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*dbly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	ax = (*dbly)->next;
	ax->n %= (*dbly)->n;
	_pop(dbly, lnum);
}
/**
 * _pstr - prints the string of the stack
 *
 * @dbly: head of the linked list
 * @lnum: line number;
 * Return: no return
 */
void _pstr(stack_t **dbly, unsigned int lnum)
{
	stack_t *ax;
	(void)lnum;

	ax = *dbly;

	while (ax && ax->n > 0 && ax->n < 128)
	{
		printf("%c", ax->n);
		ax = ax->next;
	}

	printf("\n");
}
/**
 * _pchar - print the char value of the first element
 *
 * @dbly: head of the linked list
 * @lnum: line number;
 * Return: no return
 */
void _pchar(stack_t **dbly, unsigned int lnum)
{
	if (dbly == NULL || *dbly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*dbly)->n < 0 || (*dbly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dbly)->n);
}
