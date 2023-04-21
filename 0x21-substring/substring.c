#include "substring.h"

/**
 * find_substring - Finds all the possible substrings containing.
 *
 * @s: Is the string to scan.
 * @words: Is the array of words all substrings.
 * @nb_words: Is the number of elements in the array words.
 * @n: Holds the address at which to store the number of elements.
 *
 * Return: An allocated array.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, word_len, j, i = 0, k;
	int *elements, *found;

	if (!s)
		return (NULL);
	*n = 0, len = strlen(s), word_len = strlen(words[0]);
	found = malloc(nb_words * sizeof(int));
	elements = malloc(len * sizeof(int));
	while (i <= len - nb_words * word_len)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 &&
					strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			elements[(*n)++] = i;
		i++;
	}
	free(found);
	return (elements);
}
