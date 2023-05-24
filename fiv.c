#include "shell.h"
void _putex(char *bgh)
{
	int i = 0;

	if (!bgh)
		return;
	while (bgh[i] != '\0')
	{
		_putex_char(bgh[i]);
		i++;
	}
}





int _putex_char(char c)
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







int _putxfedex(char c, int fd)
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






int _pux(char *bgh, int fd)
{
	int i = 0;

	if (!bgh)
		return (0);
	while (*bgh)
	{
		i += _putxfedex(*bgh++, fd);
	}
	return (i);
}



