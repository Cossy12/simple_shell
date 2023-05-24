#include "shell.h"



int istory_fl(main_if *main_fls)
{
	print_list(main_fls->prev_e_v);
	return (0);
}



int name_unv(main_if *main_fls, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(main_fls->name),
		get_node_index(main_fls->name, node_starts_with(main_fls->name, str, -1)));
	*p = c;
	return (ret);
}



int nam_ng_set(main_if *main_fls, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (name_unv(main_fls, str));
	name_unv(main_fls, str);
	return (add_node_end(&(main_fls->name), str, 0) == NULL);
}


int print_alias(a_l_l *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


int name_usr(main_if *main_fls)
{
	int i = 0;
	char *p = NULL;

	a_l_l *node = NULL;

	if (main_fls->argc == 1)
	{
		node = main_fls->name;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; main_fls->sil[i]; i++)
	{
		p = _strchr(main_fls->sil[i], '=');
		if (p)
			nam_ng_set(main_fls, main_fls->sil[i]);
		else
			print_alias(node_starts_with(main_fls->name, main_fls->sil[i], '='));
	}
	return (0);
}



