#include "shell.h"


char *_cat_string(char *mai_di, char *view_point, int n)
{
	int i, j;
	char *s = mai_di;

	i = 0;
	while (view_point[i] != '\0' && i < n - 1)
	{
		mai_di[i] = view_point[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			mai_di[j] = '\0';
			j++;
		}
	}
	return (s);
}

char *_opy_string(char *mai_di, char *view_point, int n)
{
	int i, j;
	char *s = mai_di;

	i = 0;
	j = 0;
	while (mai_di[i] != '\0')
		i++;
	while (view_point[j] != '\0' && j < n)
	{
		mai_di[i] = view_point[j];
		i++;
		j++;
	}
	if (j < n)
		mai_di[i] = '\0';
	return (s);
}

char *_strin_chrq(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}



