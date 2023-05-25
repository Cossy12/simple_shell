#include "shell.h"




char *_stringing_copy(char *lst_point, char *source)
{
	int i = 0;

	if (lst_point == source || source == 0)
		return (lst_point);
	while (source[i])
	{
		lst_point[i] = source[i];
		i++;
	}
	lst_point[i] = 0;
	return (lst_point);
}



char *stringing_up(const char *string)
{
	int ltng = 0;
	char *ret;

	if (string == NULL)
		return (NULL);
	while (*string++)
		ltng++;
	ret = malloc(sizeof(char) * (ltng + 1));
	if (!ret)
		return (NULL);
	for (ltng++; ltng--;)
		ret[ltng] = *--string;
	return (ret);
}



void _values(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_chrs(string[i]);
		i++;
	}
}



int _chrs(char q)
{
	static int i;
	static char nom[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, nom, i);
		i = 0;
	}
	if (q != BUF_FLUSH)
		nom[i++] = q;
	return (1);
}



