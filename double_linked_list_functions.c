#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@ahead: first position of linked list
 *@i: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **ahead, const int i)
{
	stack_t *tempo, *aux;

	if (ahead == NULL)
		return (NULL);
	tempo = malloc(sizeof(stack_t));
	if (!tempo)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tempo->n = i;
	/*Careful with the first time*/
	if (*ahead == NULL)
	{
		tempo->next = *ahead;
		tempo->prev = NULL;
		*ahead = tempo;
		return (*ahead);
	}
	aux = *ahead;
	while (aux->next)
		aux = aux->next;
	tempo->next = aux->next;
	tempo->prev = aux;
	aux->next = tempo;
	return (aux->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@ahead: first position of linked list
 *@i: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **ahead, const int i)
{
	stack_t *tempo;

	if (ahead == NULL)
		return (NULL);
	tempo = malloc(sizeof(stack_t));
	if (!tempo)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tempo->n = i;
	/*Careful with the first time*/
	if (*ahead == NULL)
	{
		tempo->next = *ahead;
		tempo->prev = NULL;
		*ahead = tempo;
		return (*ahead);
	}
	(*ahead)->prev = tempo;
	tempo->next = (*ahead);
	tempo->prev = NULL;
	*ahead = tempo;
	return (*ahead);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @ahead: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *ahead)
{
	stack_t *tempo;

	while ((tempo = ahead) != NULL)
	{
		ahead = ahead->next;
		free(tempo);
	}
}
