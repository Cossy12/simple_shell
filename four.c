#include "shell.h"


void _outpse(char *vsding)
{
	int i = 0;

	if (!vsding)
		return;
	while (vsding[i] != '\0')
	{
		_outputfsd(vsding[i]);
		i++;
	}
}

int _outputfsd(char c)
{
	static int i;
	static char bvsder[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, bvsder, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bvsder[i++] = c;
	return (1);
}



int _ouhtput(char c, int vc)
{
	static int i;
	static char bvsder[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(vc, bvsder, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		bvsder[i++] = c;
	return (1);
}



int _otyput(char *vsding, int vc)
{
	int i = 0;

	if (!vsding)
		return (0);
	while (*vsding)
	{
		i += _ouhtput(*vsding++, vc);
	}
	return (i);
}



