#include "monty.h"
/**
 * _strcmp - Compares strings
 * @s1: First string
 * @s2: Second string
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		if (*s2 == ' ')
			s2++;
		else if (*s1 == *s2)
		{
			s1++;
			s2++;
			if (*s1 == '\0' && (*s2 == ' ' || *s2 == '\n' || *s2 == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
