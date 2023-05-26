#include "shell.h"

int _historia(ret_information *main_m)
{
	enabl_lrst(main_m->shhistory);
	return (0);
}


int set_name_a(ret_information *main_m, char *str)
{
	char *p, c;
	int ret;

	p = _strin_chrq(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = rm_node_a(&(main_m->n_ame),
		access_nd(main_m->n_ame, nd_acces_pn(main_m->n_ame, str, -1)));
	*p = c;
	return (ret);
}


int new_a_name(ret_information *main_m, char *str)
{
	char *p;

	p = _strin_chrq(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (set_name_a(main_m, str));
	set_name_a(main_m, str);
	return (more_nd(&(main_m->n_ame), str, 0) == NULL);
}


int s_h_name(a_l_l *nd)
{
	char *p = NULL, *a = NULL;

	if (nd)
	{
		p = _strin_chrq(nd->shdia, '=');
		for (a = nd->shdia; a <= p; a++)
			_outpu_ty(*a);
		_outpu_ty('\'');
		_outputxw(p + 1);
		_outputxw("'\n");
		return (0);
	}
	return (1);
}


int _name_my(ret_information *main_m)
{
	int i = 0;
	char *p = NULL;

	a_l_l *nd = NULL;

	if (main_m->gramuent == 1)
	{
		nd = main_m->n_ame;
		while (nd)
		{
			s_h_name(nd);
			nd = nd->fwd;
		}
		return (0);
	}
	for (i = 1; main_m->aguments_s[i]; i++)
	{
		p = _strin_chrq(main_m->aguments_s[i], '=');
		if (p)
			new_a_name(main_m, main_m->aguments_s[i]);
		else
			s_h_name(nd_acces_pn(main_m->n_ame, main_m->aguments_s[i], '='));
	}
	return (0);
}



