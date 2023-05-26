#include "shell.h"


int haal(ret_information *mai_b_v, char **av)
{
	ssize_t r = 0;
	int info_buidfg = 0;

	while (r != -1 && info_buidfg != -2)
	{
		rm_info_rm(mai_b_v);
		if (main_interconnection(mai_b_v))
			_outputxw("$ ");
		_outputfsd(BUF_FLUSH);
		r = a_c_ess_in(mai_b_v);
		if (r != -1)
		{
			info_s_e(mai_b_v, av);
			info_buidfg = loc_a_t(mai_b_v);
			if (info_buidfg == -1)
				find_cmd(mai_b_v);
		}
		else if (main_interconnection(mai_b_v))
			_outpu_ty('\n');
		info_f_r_e(mai_b_v, 0);
	}
	v_b_dfgh(mai_b_v);
	info_f_r_e(mai_b_v, 1);
	if (!main_interconnection(mai_b_v) && mai_b_v->lvlsh)
		exit(mai_b_v->lvlsh);
	if (info_buidfg == -2)
	{
		if (mai_b_v->mn_e_rsd == -1)
			exit(mai_b_v->lvlsh);
		exit(mai_b_v->mn_e_rsd);
	}
	return (info_buidfg);
}


int loc_a_t(ret_information *mai_b_v)
{
	int i, vin_bts = -1;

	tnl_tab tblins[] = {
		{"exit", _escapade},
		{"env", _i_env},
		{"help", _myhelp},
		{"history", _historia},
		{"setenv", _curr_env},
		{"unsetenv", un_env},
		{"cd", _nav_cd},
		{"alias", _name_my},
		{NULL, NULL}
	};
	for (i = 0; tblins[i].ypes; i++)
		if (_s_t_i_ng(mai_b_v->aguments_s[0], tblins[i].ypes) == 0)
		{
			mai_b_v->cntlne_++;
			vin_bts = tblins[i].func(mai_b_v);
			break;
		}
	return (vin_bts);
}



void find_cmd(ret_information *mai_b_v)
{
	char *path = NULL;
	int i, k;

	mai_b_v->fllow = mai_b_v->aguments_s[0];
	if (mai_b_v->ln_fsg == 1)
	{
		mai_b_v->cntlne_++;
		mai_b_v->ln_fsg = 0;
	}
	for (i = 0, k = 0; mai_b_v->huguments[i]; i++)
		if (!value_is(mai_b_v->huguments[i], " \t\n"))
			k++;
	if (!k)
		return;
	path = fll_w_he(mai_b_v, _sele_tenv(mai_b_v, "PATH="), mai_b_v->aguments_s[0]);
	if (path)
	{
		mai_b_v->fllow = path;
		c_m_adddd(mai_b_v);
	}
	else
	{
		if ((main_interconnection(mai_b_v) || _sele_tenv(mai_b_v, "PATH=")
			|| mai_b_v->aguments_s[0][0] == '/') && command_cd(mai_b_v, mai_b_v->aguments_s[0]))
			c_m_adddd(mai_b_v);
		else if (*(mai_b_v->huguments) != '\n')
		{
			mai_b_v->lvlsh = 127;
			show_issue(mai_b_v, "found\n");
		}
	}
}



void c_m_adddd(ret_information *mai_b_v)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(mai_b_v->fllow, mai_b_v->aguments_s, fetch_env_(mai_b_v)) == -1)
		{
			info_f_r_e(mai_b_v, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(mai_b_v->lvlsh));
		if (WIFEXITED(mai_b_v->lvlsh))
		{
			mai_b_v->lvlsh = WEXITSTATUS(mai_b_v->lvlsh);
			if (mai_b_v->lvlsh == 126)
				show_issue(mai_b_v, " denied\n");
		}
	}
}



