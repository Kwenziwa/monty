#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 * @dbly: hdn of the linked list
 * @lnum: line number
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void _add(stack_t **dbly, unsigned int lnum)
{
	int k = 0;
	stack_t *ux = NULL;

	ux = *dbly;

	for (; ux != NULL; ux = ux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	ux = (*dbly)->next;
	ux->n += (*dbly)->n;
	_pop(dbly, lnum);
}

/**
 * _nop - doesn't do anything
 * @dbly: linked list hdn
 * @lnum: line number
 */
void _nop(stack_t **dbly, unsigned int lnum)
{
	(void)dbly;
	(void)lnum;
}
/**
 * _sub - Subtracts 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @lnum: the line number
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void _sub(stack_t **hdn, unsigned int lnum)
{
	int k = 0;
	stack_t *crrnt;

	crrnt = *hdn;

	for (; crrnt != NULL; crrnt = crrnt->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	crrnt = (*hdn)->next;
	crrnt->n -= (*hdn)->n;
	_pop(hdn, lnum);
}

/**
 *_div -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @dbly: hdn of the linked list
 * @lnum: line number;
 * Return: no return
 */

void _div(stack_t **dbly, unsigned int lnum)
{
	int k = 0;
	stack_t *ux = NULL;

	ux = *dbly;

	for (; ux != NULL; ux = ux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*dbly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	ux = (*dbly)->next;
	ux->n /= (*dbly)->n;
	_pop(dbly, lnum);
}

/**
 *_mul -Multiplies 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @lnum: the line number
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void _mul(stack_t **hdn, unsigned int lnum)
{
	int k = 0;
	stack_t *crrnt;

	crrnt = *hdn;

	for (; crrnt != NULL; crrnt = crrnt->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", lnum);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	crrnt = (*hdn)->next;
	crrnt->n *= (*hdn)->n;
	_pop(hdn, lnum);
}
