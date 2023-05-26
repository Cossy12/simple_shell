#include "shell.h"


int command_cd(ret_information *form_info, char *fllw_n_b)
{
	struct stat st;
	(void)form_info;

	if (!fllw_n_b || stat(fllw_n_b, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

char *characters_ne_d(char *fllw_sting, int gos, int ndeend)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = gos; i < ndeend; i++)
		if (fllw_sting[i] != ':')
			buf[k++] = fllw_sting[i];
	buf[k] = 0;
	return (buf);
}


char *fll_w_he(ret_information *form_info, char *fllw_sting, char *commad)
{
	int i = 0, rn_place = 0;
	char *fllw_n_b;

	if (!fllw_sting)
		return (NULL);
	if ((_lng_str_i(commad) > 2) && begi_ns(commad, "./"))
	{
		if (command_cd(form_info, commad))
			return (commad);
	}
	while (1)
	{
		if (!fllw_sting[i] || fllw_sting[i] == ':')
		{

			fllw_n_b = characters_ne_d(fllw_sting, rn_place, i);
			if (!*fllw_n_b)
				_c_a_t_string(fllw_n_b, commad);
			else
			{
				_c_a_t_string(fllw_n_b, "/");
				_c_a_t_string(fllw_n_b, commad);
			}
			if (command_cd(form_info, fllw_n_b))
				return (fllw_n_b);
			if (!fllw_sting[i])
				break;
			rn_place = i;
		}
		i++;
	}
	return (NULL);
}



