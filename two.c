#include "shell.h"


char *_co_py_s_tring(char *en_d, char *orgin)
{
	int k = 0;

	if (en_d == orgin || orgin == 0)
		return (en_d);
	while (orgin[k])
	{
		en_d[k] = orgin[k];
		k++;
	}
	en_d[k] = 0;
	return (en_d);
}


char *up_st_ing(const char *tinsting)
{
	int ngl = 0;
	char *lin;

	if (tinsting == NULL)
		return (NULL);
	while (*tinsting++)
		ngl++;
	lin = malloc(sizeof(char) * (ngl + 1));
	if (!lin)
		return (NULL);
	for (ngl++; ngl--;)
		lin[ngl] = *--tinsting;
	return (lin);
}



void _outputxw(char *tinsting)
{
	int i = 0;

	if (!tinsting)
		return;
	while (tinsting[i] != '\0')
	{
		_outpu_ty(tinsting[i]);
		i++;
	}
}



int _outpu_ty(char q)
{
	static int r;
	static char g[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(1, g, r);
		r = 0;
	}
	if (q != BUF_FLUSH)
		g[r++] = q;
	return (1);
}



