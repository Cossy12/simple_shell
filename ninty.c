#include "shell.h"



void rm_info_rm(ret_information *kfform)
{
	kfform->huguments = NULL;
	kfform->aguments_s = NULL;
	kfform->fllow = NULL;
	kfform->gramuent = 0;
}



void info_s_e(ret_information *kfform, char **av)
{
	int i = 0;

	kfform->n_ma = av[0];
	if (kfform->huguments)
	{
		kfform->aguments_s = v_o_column(kfform->huguments, " \t");
		if (!kfform->aguments_s)
		{
			kfform->aguments_s = malloc(sizeof(char *) * 2);
			if (kfform->aguments_s)
			{
				kfform->aguments_s[0] = up_st_ing(kfform->huguments);
				kfform->aguments_s[1] = NULL;
			}
		}
		for (i = 0; kfform->aguments_s && kfform->aguments_s[i]; i++)
			;
		kfform->gramuent = i;
		a_l_newname(kfform);
		variables_nw(kfform);
	}
}



void info_f_r_e(ret_information *kfform, int all)
{
	ree_fre(kfform->aguments_s);
	kfform->aguments_s = NULL;
	kfform->fllow = NULL;

	if (all)
	{
		if (!kfform->md_bff)
			free(kfform->huguments);
		if (kfform->venf)
			un_list_free(&(kfform->venf));
		if (kfform->shhistory)
			un_list_free(&(kfform->shhistory));
		if (kfform->n_ame)
			un_list_free(&(kfform->n_ame));
		ree_fre(kfform->vironment);
			kfform->vironment = NULL;
		ref_ee((void **)kfform->md_bff);
		if (kfform->filerdn > 2)
			close(kfform->filerdn);
		_outpu_ty(BUF_FLUSH);
	}
}



