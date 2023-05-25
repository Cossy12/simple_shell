#include "shell.h"



int view_command(main_fl *fl_in, char *lcked)
{
	struct stat st;
	(void)fl_in;

	if (!lcked || stat(lcked, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}



char *two_chrs(char *lckroute, int ign, int alt)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = ign; i < alt; i++)
		if (lckroute[i] != ':')
			buf[k++] = lckroute[i];
	buf[k] = 0;
	return (buf);
}


char *lckpth(main_fl *fl_in, char *lckroute, char *command)
{
	int i = 0, position_as_per = 0;
	char *lcked;

	if (!lckroute)
		return (NULL);
	if ((_lenstr(command) > 2) && ignss_with(command, "./"))
	{
		if (view_command(fl_in, command))
			return (command);
	}
	while (1)
	{
		if (!lckroute[i] || lckroute[i] == ':')
		{

			lcked = two_chrs(lckroute, position_as_per, i);
			if (!*lcked)
				_catstr(lcked, command);
			else
			{
				_catstr(lcked, "/");
				_catstr(lcked, command);
			}
			if (view_command(fl_in, lcked))
				return (lcked);
			if (!lckroute[i])
				break;
			position_as_per = i;
		}
		i++;
	}
	return (NULL);
}



