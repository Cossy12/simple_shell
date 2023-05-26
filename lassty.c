#include "shell.h"



int ch_vsq(ret_information *main_fo_qs, char *bvuvvs, size_t *p)
{
	size_t j = *p;

	if (bvuvvs[j] == '|' && bvuvvs[j + 1] == '|')
	{
		bvuvvs[j] = 0;
		j++;
		main_fo_qs->u_t_b_tybf = CMD_OR;
	}
	else if (bvuvvs[j] == '&' && bvuvvs[j + 1] == '&')
	{
		bvuvvs[j] = 0;
		j++;
		main_fo_qs->u_t_b_tybf = CMD_AND;
	}
	else if (bvuvvs[j] == ';') 
	{
		bvuvvs[j] = 0;
		main_fo_qs->u_t_b_tybf = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}


void accv_ch(ret_information *main_fo_qs, char *bvuvvs, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (main_fo_qs->u_t_b_tybf == CMD_AND)
	{
		if (main_fo_qs->lvlsh)
		{
			bvuvvs[i] = 0;
			j = len;
		}
	}
	if (main_fo_qs->u_t_b_tybf == CMD_OR)
	{
		if (!main_fo_qs->lvlsh)
		{
			bvuvvs[i] = 0;
			j = len;
		}
	}
	*p = j;
}



int a_l_newname(ret_information *main_fo_qs)
{
	int i;
	a_l_l *nd_dnd;
	char *p;

	for (i = 0; i < 10; i++)
	{
		nd_dnd = nd_acces_pn(main_fo_qs->n_ame, main_fo_qs->aguments_s[0], '=');
		if (!nd_dnd)
			return (0);
		free(main_fo_qs->aguments_s[0]);
		p = _strin_chrq(nd_dnd->shdia, '=');
		if (!p)
			return (0);
		p = up_st_ing(p + 1);
		if (!p)
			return (0);
		main_fo_qs->aguments_s[0] = p;
	}
	return (1);
}



int variables_nw(ret_information *main_fo_qs)
{
	int i = 0;

	a_l_l *nd_dnd;

	for (i = 0; main_fo_qs->aguments_s[i]; i++)
	{
		if (main_fo_qs->aguments_s[i][0] != '$' || !main_fo_qs->aguments_s[i][1])
			continue;
		if (!_s_t_i_ng(main_fo_qs->aguments_s[i], "$?"))
		{
			ting_rpsd(&(main_fo_qs->aguments_s[i]),
				up_st_ing(cnvt_no(main_fo_qs->lvlsh, 10, 0)));
			continue;
		}
		if (!_s_t_i_ng(main_fo_qs->aguments_s[i], "$$"))
		{
			ting_rpsd(&(main_fo_qs->aguments_s[i]),
				up_st_ing(cnvt_no(getpid(), 10, 0)));
			continue;
		}
		nd_dnd = nd_acces_pn(main_fo_qs->venf, &main_fo_qs->aguments_s[i][1], '=');
		if (nd_dnd)
		{
			ting_rpsd(&(main_fo_qs->aguments_s[i]),
				up_st_ing(_strin_chrq(nd_dnd->shdia, '=') + 1));
			continue;
		}
		ting_rpsd(&main_fo_qs->aguments_s[i], up_st_ing(""));
	}
	return (0);
}


int ting_rpsd(char **burs, char *ltst)
{
	free(*burs);

	*burs = ltst;

	return (1);
}



