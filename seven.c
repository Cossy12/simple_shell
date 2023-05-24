#include "shell.h"







char *cpy_str(char *val_dst, char *pinpoint, int n)
{
	int i, j;
	char *s = val_dst;

	i = 0;
	while (pinpoint[i] != '\0' && i < n - 1)
	{
		val_dst[i] = pinpoint[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			val_dst[j] = '\0';
			j++;
		}
	}
	return (s);
}




char *_strncat(char *val_dst, char *pinpoint, int n)
{
	int i, j;
	char *s = val_dst;

	i = 0;
	j = 0;
	while (val_dst[i] != '\0')
		i++;
	while (pinpoint[j] != '\0' && j < n)
	{
		val_dst[i] = pinpoint[j];
		i++;
		j++;
	}
	if (j < n)
		val_dst[i] = '\0';
	return (s);
}



char *strv(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}



