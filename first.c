#include "shell.h"


int rdfl(main_if *fxl)
{
	return (rdflfile(STDIN_FILENO) && fxl->filrd <= 2);
}

int val_is(char c, char *valinx)
{
	while (*valinx)
		if (*valinx++ == c)
			return (1);
	return (0);
}

int val_nm(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int valu_sh(char *s)
{
	int i, innnit = 1, sig_al = 0, answr;
	unsigned int exp = 0;

	for (i = 0;  s[i] != '\0' && sig_al != 2; i++)
	{
		if (s[i] == '-')
			innnit *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			sig_al = 1;
			exp *= 10;
			exp += (s[i] - '0');
		}
		else if (sig_al == 1)
			sig_al = 2;
	}
	if (innnit == -1)
		answr = -exp;
	else
		answr = exp;
	return (answr);
}



