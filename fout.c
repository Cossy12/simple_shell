#include "shell.h"


int _prov_errors(char *f)
{
	int i = 0;
	unsigned long int nswr = 0;

	if (*f == '+')
		f++;  
	for (i = 0;  f[i] != '\0'; f++)
	{
		if (f[i] >= '0' && f[i] <= '9')
		{
			nswr *= 10;
			nswr += (f[i] - '0');
			if (nswr > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (nswr);
}



void show_issue(ret_information *info, char *estr)
{
	_outpse(info->n_ma);
	_outpse(": ");
	shw_a_l(info->cntlne_, STDERR_FILENO);
	_outpse(": ");
	_outpse(info->aguments_s[0]);
	_outpse(": ");
	_outpse(estr);
}



int shw_a_l(int input, int fd)
{
	int (*__putchar)(char) = _outpu_ty;
	int i, count = 0;
	unsigned int _mnow, npre;

	if (fd == STDERR_FILENO)
		__putchar = _outputfsd;
	if (input < 0)
	{
		_mnow = -input;
		__putchar('-');
		count++;
	}
	else
		_mnow = input;
	npre = _mnow;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_mnow / i)
		{
			__putchar('0' + npre / i);
			count++;
		}
		npre %= i;
	}
	__putchar('0' + npre);
	count++;
	return (count);
}




char *cnvt_no(long int num, int base, int flags)
{
	static char *rry;
	static char buffer[50];
	char gno = 0;
	char *bvi;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		gno = '-';
	}
	rry = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	bvi = &buffer[49];
	*bvi = '\0';
	do	{
		*--bvi = rry[n % base];
		n /= base;
	} while (n != 0);
	if (gno)
		*--bvi = gno;
	return (bvi);
}





void rm_cm(char *uf)
{
	int d;

	for (d = 0; uf[d] != '\0'; d++)
		if (uf[d] == '#' && (!d || uf[d - 1] == ' '))
		{
			uf[d] = '\0';
			break;
		}
}



