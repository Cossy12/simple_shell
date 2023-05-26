#include "shell.h"




int main_interconnection(ret_information *main_inf)
{
	return (isatty(STDIN_FILENO) && main_inf->filerdn <= 2);
}



int value_is(char c, char *valuef_is)
{
	while (*valuef_is)
		if (*valuef_is++ == c)
			return (1);
	return (0);
}



int _i_s_main(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}



int _i_s_fn(char *x)
{
	int i, sng = 1, shw = 0, rslt;
	unsigned int answ = 0;

	for (i = 0;  x[i] != '\0' && shw != 2; i++)
	{
		if (x[i] == '-')
			sng *= -1;
		if (x[i] >= '0' && x[i] <= '9')
		{
			shw = 1;
			answ *= 10;
			answ += (x[i] - '0');
		}
		else if (shw == 1)
			shw = 2;
	}
	if (sng == -1)
		rslt = -answ;
	else
		rslt = answ;
	return (rslt);
}



