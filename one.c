#include "shell.h"


int ive(main_fl *info)
{
	return (isatty(STDIN_FILENO) && info->fr <= 2);
}

int im(char c, char *hy)
{
	while (*hy)
		if (*hy++ == c)
			return (1);
	return (0);
}

int lpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int _toi(char *s)
{
	int i, gns = 1, gf = 0, ut;
	unsigned int answer = 0;

	for (i = 0;  s[i] != '\0' && gf != 2; i++)
	{
		if (s[i] == '-')
			gns *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			gf = 1;
			answer *= 10;
			answer += (s[i] - '0');
		}
		else if (gf == 1)
			gf = 2;
	}
	if (gns == -1)
		ut = -answer;
	else
		ut = answer;
	return (ut);
}



