#include "shell.h"





int erro_ed(char *s)
{
	int i = 0;
	unsigned long int ans_er = 0;

	if (*s == '+')
		s++;  
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans_er *= 10;
			ans_er += (s[i] - '0');
			if (ans_er > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (ans_er);
}





void show_error(main_if *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	show_vlx(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->sil[0]);
	_eputs(": ");
	_eputs(estr);
}


int _putchar(char);



int show_vlx(int input, int fd)
{
	int (*_valerias)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		_valerias = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		_valerias('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			_valerias('0' + current / i);
			count++;
		}
		current %= i;
	}
	_valerias('0' + current);
	count++;
	return (count);
}






char *chng_number(long int num, int base, int flags)
{
	static char *arry;
	static char bffed[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arry = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &bffed[49];
	*ptr = '\0';
	do	{
		*--ptr = arry[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}






void rm_cm(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}








