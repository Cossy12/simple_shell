#include "shell.h"





char **env_ron(main_if *svrl)
{
	if (!svrl->viron || svrl->env_dfed)
	{
		svrl->viron = list_to_strings(svrl->env);
		svrl->env_dfed = 0;
	}
	return (svrl->viron);
}




int pr_env(main_if *svrl, char *var)
{
	a_l_l *nd_e = svrl->env;
	size_t i = 0;
	char *p;

	if (!nd_e || !var)
		return (0);
	while (nd_e)
	{
		p = go_strat(nd_e->str, var);
		if (p && *p == '=')
		{
			svrl->env_dfed = dn_nd_e(&(svrl->env), i);
			i = 0;
			nd_e = svrl->env;
			continue;
		}
		nd_e = nd_e->next;
		i++;
	}
	return (svrl->env_dfed);
}



int env_stgh(main_if *svrl, char *var, char *value)
{
	char *buf = NULL;
	a_l_l *nd_e;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	nd_e = svrl->env;
	while (nd_e)
	{
		p = starts_with(nd_e->str, var);
		if (p && *p == '=')
		{
			free(nd_e->str);
			nd_e->str = buf;
			svrl->env_dfed = 1;
			return (0);
		}
		nd_e = nd_e->next;
	}
	add_nd_e_end(&(svrl->env), buf, 0);
	free(buf);
	svrl->env_dfed = 1;
	return (0);
}



