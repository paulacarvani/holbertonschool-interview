#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: fist char
 * @s2: second char
 *
 * Return: returns 1 considered identical otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' || *s2 == '\0')
	{
		if (*s2 == '*')
		{
			if (*(s2 + 1) == '*')
				return (wildcmp(s1, s2 + 1));
			if (*(s2 + 1) == '\0')
				return (1);
			return (0);
		}
		return (*s1 == *s2);
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (*s1 == *(s2 + 1))
			if (wildcmp(s1, s2 + 1) == 1)
				return (1);
		return (wildcmp(s1 + 1, s2));
	}
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
