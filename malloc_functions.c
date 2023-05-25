#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @s_one: type str compared
 * @s_two: type str compared
 * Return: 0 if s_one and s_two are equals.
 *         another value if they are different
 */
int _strcmp(char *s_one, char *s_two)
{
	int i;

	for (i = 0; s_one[i] == s_two[i] && s_one[i]; i++)
		;
	if (s_one[i] > s_two[i])
		return (1);
	if (s_one[i] < s_two[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @sr: string to review
 * @cf: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *sr, char cf)
{
	int cont = 0;

	while (sr[cont] != '\0')
	{
		if (sr[cont] == cf)
		{
			break;
		}
		cont++;
	}
	if (sr[cont] == cf)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @sr: string to cut in parts
 * @deli: delimiters
 * Return: first partition
 */
char *_strtoky(char *sr, char *deli)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!sr)
		sr = ultimo;
	while (sr[i] != '\0')
	{
		if (_sch(deli, sr[i]) == 0 && sr[i + 1] == '\0')
		{
			ultimo = sr + i + 1;
			*ultimo = '\0';
			sr = sr + j;
			return (sr);
		}
		else if (_sch(deli, sr[i]) == 0 && _sch(deli, sr[i + 1]) == 0)
			i++;
		else if (_sch(deli, sr[i]) == 0 && _sch(deli, sr[i + 1]) == 1)
		{
			ultimo = sr + i + 1;
			*ultimo = '\0';
			ultimo++;
			sr = sr + j;
			return (sr);
		}
		else if (_sch(deli, sr[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
