#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @dbly: head of the linked list
 * @lnum: line number
 * Return: no return
 */
void _push(stack_t **dbly, unsigned int lnum)
{
	int w, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", lnum);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", lnum);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	w = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(dbly, w);
	else
		add_dnodeint_end(dbly, w);
}

/**
 * _pall - prints all values on the stack
 *
 * @dbly: head of the linked list
 * @lnum: line numbers
 * Return: no return
 */
void _pall(stack_t **dbly, unsigned int lnum)
{
	stack_t *ux;
	(void)lnum;

	ux = *dbly;

	while (ux)
	{
		printf("%d\n", ux->n);
		ux = ux->next;
	}
}


/**
 * _pint - prints the value at the top of the stack
 *
 * @dbly: head of the linked list
 * @lnum: line number
 * Return: no return
 */
void _pint(stack_t **dbly, unsigned int lnum)
{
	(void)lnum;

	if (*dbly == NULL)
	{
		dprintf(2, "L%u: ", lnum);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dbly)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @dbly: head of the linked list
 * @lnum: line number
 * Return: no return
 */
void _pop(stack_t **dbly, unsigned int lnum)
{
	stack_t *ux;

	if (dbly == NULL || *dbly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	ux = *dbly;
	*dbly = (*dbly)->next;
	free(ux);
}


/**
 * _swap - swaps the top two elements of the stack
 *
 * @dbly: head of the linked list
 * @lnum: line number
 * Return: no return
 */
void _swap(stack_t **dbly, unsigned int lnum)
{
	int b = 0;
	stack_t *ux = NULL;

	ux = *dbly;

	for (; ux != NULL; ux = ux->next, b++)
		;

	if (b < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	ux = *dbly;
	*dbly = (*dbly)->next;
	ux->next = (*dbly)->next;
	ux->prev = *dbly;
	(*dbly)->next = ux;
	(*dbly)->prev = NULL;
}
