#include "shell.h"


int _escapade(ret_information *mn_fl)
{
	int escapade_chk;

	if (mn_fl->aguments_s[1]) 
	{
		escapade_chk = _prov_errors(mn_fl->aguments_s[1]);
		if (escapade_chk == -1)
		{
			mn_fl->lvlsh = 2;
			show_issue(mn_fl, "unkonwn number: ");
			_outpse(mn_fl->aguments_s[1]);
			_outputfsd('\n');
			return (1);
		}
		mn_fl->mn_e_rsd = _prov_errors(mn_fl->aguments_s[1]);
		return (-2);
	}
	mn_fl->mn_e_rsd = -1;
	return (-2);
}



int _nav_cd(ret_information *mn_fl)
{
	char *k, *rectory, buffer[1024];
	int brq_ch;

	k = getcwd(buffer, 1024);
	if (!k)
		_outputxw("msg here<<\n");
	if (!mn_fl->aguments_s[1])
	{
		rectory = _sele_tenv(mn_fl, "home=");
		if (!rectory)
			brq_ch = 
				chdir((rectory = _sele_tenv(mn_fl, "pwd=")) ? rectory : "/");
		else
			brq_ch = chdir(rectory);
	}
	else if (_s_t_i_ng(mn_fl->aguments_s[1], "-") == 0)
	{
		if (!_sele_tenv(mn_fl, "prepwd="))
		{
			_outputxw(k);
			_outpu_ty('\n');
			return (1);
		}
		_outputxw(_sele_tenv(mn_fl, "prepwd=")), _outpu_ty('\n');
		brq_ch = 
			chdir((rectory = _sele_tenv(mn_fl, "prepwd=")) ? rectory : "/");
	}
	else
		brq_ch = chdir(mn_fl->aguments_s[1]);
	if (brq_ch == -1)
	{
		show_issue(mn_fl, "c cd to ");
		_outpse(mn_fl->aguments_s[1]), _outputfsd('\n');
	}
	else
	{
		_act_env(mn_fl, "prepwd", _sele_tenv(mn_fl, "pwd="));
		_act_env(mn_fl, "pwd", getcwd(buffer, 1024));
	}
	return (0);
}


int _myhelp(ret_information *mn_fl)
{
	char **argument_arr;

	argument_arr = mn_fl->aguments_s;
	_outputxw("yet impled \n");
	if (0)
		_outputxw(*argument_arr); 
	return (0);
}



