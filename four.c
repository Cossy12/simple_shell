#include "shell.h"


char *_stringedcopy(char *lckbase, char *main_pnt, int n)
{
	int i, j;
	char *s = lckbase;

	i = 0;
	while (main_pnt[i] != '\0' && i < n - 1)
	{
		lckbase[i] = main_pnt[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			lckbase[j] = '\0';
			j++;
		}
	}
	return (s);
}

char *_stringedcat(char *lckbase, char *main_pnt, int n)
{
	int i, j;
	char *s = lckbase;

	i = 0;
	j = 0;
	while (lckbase[i] != '\0')
		i++;
	while (main_pnt[j] != '\0' && j < n)
	{
		lckbase[i] = main_pnt[j];
		i++;
		j++;
	}
	if (j < n)
		lckbase[i] = '\0';
	return (s);
}

char *_stringedchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}



