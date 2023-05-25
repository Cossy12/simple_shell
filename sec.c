#include "shell.h"




void ts(char *bkr)
{
	int i = 0;

	if (!bkr)
		return;
	while (bkr[i] != '\0')
	{
		_har(bkr[i]);
		i++;
	}
}




int _har(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}




int fkpt(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}



int fkpts(char *bkr, int fd)
{
	int i = 0;

	if (!bkr)
		return (0);
	while (*bkr)
	{
		i += fkpt(*bkr++, fd);
	}
	return (i);
}



