#include "shell.h"




char **fetch_env_(ret_information *ma_infl_)
{
	if (!ma_infl_->vironment || ma_infl_->venv_und)
	{
		ma_infl_->vironment = a_l_lo_strings(ma_infl_->venf);
		ma_infl_->venv_und = 0;
	}
	return (ma_infl_->vironment);
}



int _declunenv(ret_information *ma_infl_, char *rva)
{
	a_l_l *nds = ma_infl_->venf;
	size_t i = 0;
	char *p;

	if (!nds || !rva)
		return (0);
	while (nds)
	{
		p = begi_ns(nds->shdia, rva);
		if (p && *p == '=')
		{
			ma_infl_->venv_und = rm_node_a(&(ma_infl_->venf), i);
			i = 0;
			nds = ma_infl_->venf;
			continue;
		}
		nds = nds->fwd;
		i++;
	}
	return (ma_infl_->venv_und);
}



int _act_env(ret_information *ma_infl_, char *rva, char *value)
{
	char *uff = NULL;
	a_l_l *nds;
	char *p;

	if (!rva || !value)
		return (0);
	uff = malloc(_lng_str_i(rva) + _lng_str_i(value) + 2);
	if (!uff)
		return (1);
	_co_py_s_tring(uff, rva);
	_c_a_t_string(uff, "=");
	_c_a_t_string(uff, value);
	nds = ma_infl_->venf;
	while (nds)
	{
		p = begi_ns(nds->shdia, rva);
		if (p && *p == '=')
		{
			free(nds->shdia);
			nds->shdia = uff;
			ma_infl_->venv_und = 1;
			return (0);
		}
		nds = nds->fwd;
	}
	more_nd(&(ma_infl_->venf), uff, 0);
	free(uff);
	ma_infl_->venv_und = 1;
	return (0);
}



