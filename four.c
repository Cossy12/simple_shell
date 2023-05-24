#include "shell.h"



int env_fl(main_if *main_fls)
{
	print_list_str(main_fls->env);
	return (0);
}



char *ftch_env(main_if *main_fls, const char *name)
{
	a_l_l *fnode = main_fls->env;
	char *p;

	while (fnode)
	{
		p = starts_with(fnode->str, name);
		if (p && *p)
			return (p);
		fnode = fnode->next;
	}
	return (NULL);
}



int rn_env(main_if *main_fls)
{
	if (main_fls->argc != 3)
	{
		_eputs("unrecognized number of arg\n");
		return (1);
	}
	if (_setenv(main_fls, main_fls->sil[1], main_fls->sil[2]))
		return (0);
	return (1);
}




int psv_env(main_if *main_fls)
{
	int i;

	if (main_fls->argc == 1)
	{
		_eputs(" less arg.\n");
		return (1);
	}
	for (i = 1; i <= main_fls->argc; i++)
		_unsetenv(main_fls, main_fls->sil[i]);
	return (0);
}



int fill_env(main_if *main_fls)
{

	a_l_l *fnode = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&fnode, environ[i], 0);
	main_fls->env = fnode;
	return (0);
    
}




