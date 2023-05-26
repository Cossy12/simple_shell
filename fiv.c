#include "shell.h"


int _i_env(ret_information *main_f)
{
	l_sty(main_f->venf);
	return (0);
}



char *_sele_tenv(ret_information *main_f, const char *name)
{
	a_l_l *ndd = main_f->venf;
	char *p;

	while (ndd)
	{
		p = begi_ns(ndd->shdia, name);
		if (p && *p)
			return (p);
		ndd = ndd->fwd;
	}
	return (NULL);
}



int _curr_env(ret_information *main_f)
{
	if (main_f->gramuent != 3)
	{
		_outpse("Incorrect number of arguements\n");
		return (1);
	}
	if (_act_env(main_f, main_f->aguments_s[1], main_f->aguments_s[2]))
		return (0);
	return (1);
}



int un_env(ret_information *main_f)
{
	int i;

	if (main_f->gramuent == 1)
	{
		_outpse("very few arguements.\n");
		return (1);
	}
	for (i = 1; i <= main_f->gramuent; i++)
		_declunenv(main_f, main_f->aguments_s[i]);
	return (0);
}





int fill_env(ret_information *main_f)
{
	a_l_l *ndd = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		more_nd(&ndd, environ[v], 0);
	main_f->venf = ndd;
	return (0);
}




