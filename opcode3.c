#include "monty.h"

/**
 * _rotl - rotates 1st element to the bottom and 2nd to the top
 * @dbly: linked list head
 * @lnum: line nummber
 */
void _rotl(stack_t **dbly, unsigned int lnum)
{
	stack_t *auxa = NULL;
	stack_t *auxb = NULL;
	(void)lnum;

	if (*dbly == NULL)
		return;

	if ((*dbly)->next == NULL)
		return;

	auxa = (*dbly)->next;
	auxb = *dbly;

	for (; auxb->next != NULL; auxb = auxb->next)
		;

	auxa->prev = NULL;
	auxb->next = *dbly;
	(*dbly)->next = NULL;
	(*dbly)->prev = auxb;
	*dbly = auxa;
}

/**
 * _rotr - reverse stack
 * @dbly: linked list head
 * @lnum: line number
 */
void _rotr(stack_t **dbly, unsigned int lnum)
{
	stack_t *ux = NULL;
	(void)lnum;

	if (*dbly == NULL)
		return;

	if ((*dbly)->next == NULL)
		return;

	ux = *dbly;

	for (; ux->next != NULL; ux = ux->next)
		;

	ux->prev->next = NULL;
	ux->next = *dbly;
	ux->prev = NULL;
	(*dbly)->prev = ux;
	*dbly = ux;
}

