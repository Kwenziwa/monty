#include "monty.h"
void (*f)(stack_t **stack, unsigned int line_number);
global_t vglo;
/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @file_d: file descriptor
 * Return: no return
 */
void start_vglo(FILE *file_d)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = file_d;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @ac: argument count
 * @av: argument vector
 * Return: file struct
 */
FILE *check_input(int ac, char *av[])
{
	FILE *file_d;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_d = fopen(av[1], "r");

	if (file_d == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (file_d);
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	FILE *file_d;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	file_d = check_input(ac, av);
	start_vglo(file_d);
	nlines = getline(&vglo.buffer, &size, file_d);
	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, file_d);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}

