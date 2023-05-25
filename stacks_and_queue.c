#include "monty.h"

/**
 * _queue - sets format of data to queue(FIFI/LILO)
 * @dbly: head of linked list
 * @lnum: line number
 */
void _queue(stack_t **dbly, unsigned int lnum)
{
	(void)dbly;
	(void)lnum;

	vglo.lifo = 0;
}

/**
 * _stack - sets format of data to stack (LIFO/FILO)
 * @dbly: linked list head
 * @lnum: line number
 */
void _stack(stack_t **dbly, unsigned int lnum)
{
	(void)dbly;
	(void)lnum;

	vglo.lifo = 1;
}
