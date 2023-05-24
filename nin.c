#include "shell.h"


void erase_info(main_if *info)
{
	info->arg = NULL;
	info->sil = NULL;
	info->path = NULL;
	info->argc = 0;
}

void define_info(main_if *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->sil = strtow(info->arg, " \t");
		if (!info->sil)
		{
			info->sil = malloc(sizeof(char *) * 2);
			if (info->sil)
			{
				info->sil[0] = _strdup(info->arg);
				info->sil[1] = NULL;
			}
		}
		for (i = 0; info->sil && info->sil[i]; i++)
			;
		info->argc = i;
		new_alias(info);
		new_vars(info);
	}
}

void access_info(main_if *info, int all)
{
	facesxib(info->sil);
	info->sil = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->fdg_buf)
			acesxib(info->arg);
		if (info->env)
			acesxib_list(&(info->env));
		if (info->prev_e_v)
			acesxib_list(&(info->prev_e_v));
		if (info->name)
			acesxib_list(&(info->name));
		facesxib(info->viron);
			info->viron = NULL;
		bacesxib((void **)info->fdg_buf);
		if (info->filrd > 2)
			close(info->filrd);
		_putchar(BUF_FLUSH);
	}
}



