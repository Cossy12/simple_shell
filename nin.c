#include "shell.h"




int string_length(char *w)
{
	int i = 0;

	if (!w)
		return (0);
	while (*w++)
		i++;
	return (i);
}





int string_type(char *ys, char *yss)
{
	while (*ys && *yss)
	{
		if (*ys != *yss)
			return (*ys - *yss);
		ys++;
		yss++;
	}
	if (*ys == *yss)
		return (0);
	else
		return (*ys < *yss ? -1 : 1);
}



char *ign_nums(const char *all_values, const char *vlndls)
{
	while (*vlndls)
		if (*vlndls++ != *all_values++)
			return (NULL);
	return ((char *)all_values);
}



char *_strcat(char *endings, char *point)
{
	char *answed = endings;

	while (*endings)
		endings++;
	while (*point)
		*endings++ = *point++;
	*endings = *point;
	return (answed);
}



