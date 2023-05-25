#include "shell.h"


int thi_eror(char *s)
{
	int i = 0;
	unsigned long int answer = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			answer *= 10;
			answer += (s[i] - '0');
			if (answer > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (answer);
}

void err_shw(main_fl *info, char *vstr)
{
	ts(info->fr_name);
	ts(": ");
	vl_print(info->coun_ted, STDERR_FILENO);
	ts(": ");
	ts(info->grv[0]);
	ts(": ");
	ts(vstr);
}



int vl_print(int input, int fd)
{
	int (*__har)(char) = _chrs;
	int i, count = 0;
	unsigned int bs_, current;

	if (fd == STDERR_FILENO)
		__har = _har;
	if (input < 0)
	{
		bs_ = -input;
		__har('-');
		count++;
	}
	else
		bs_ = input;
	current = bs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (bs_ / i)
		{
			__har('0' + current / i);
			count++;
		}
		current %= i;
	}
	__har('0' + current);
	count++;
	return (count);
}

char *nm_cnvt(long int num, int base, int sign_shwn)
{
	static char *brck;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(sign_shwn & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	brck = sign_shwn & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do	{
		*--ptr = brck[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}



void rmcm(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}



