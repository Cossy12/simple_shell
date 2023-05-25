#include "shell.h"




all_ *new_fstnd(all_ **hd, const char *str, int num)
{
	all_ *new_hd;

	if (!hd)
		return (NULL);
	new_hd = malloc(sizeof(all_));
	if (!new_hd)
		return (NULL);
	_set((void *)new_hd, 0, sizeof(all_));
	new_hd->num = num;
	if (str)
	{
		new_hd->str = _stringupup(str);
		if (!new_hd->str)
		{
			free(new_hd);
			return (NULL);
		}
	}
	new_hd->next = *hd;
	*hd = new_hd;
	return (new_hd);
}



all_ *new_fstnd_end(all_ **hd, const char *str, int num)
{
	all_ *new_fstnd, *fstnd;

	if (!hd)
		return (NULL);
	fstnd = *hd;
	new_fstnd = malloc(sizeof(all_));
	if (!new_fstnd)
		return (NULL);
	_set((void *)new_fstnd, 0, sizeof(all_));
	new_fstnd->num = num;
	if (str)
	{
		new_fstnd->str = _stringupup(str);
		if (!new_fstnd->str)
		{
			free(new_fstnd);
			return (NULL);
		}
	}
	if (fstnd)
	{
		while (fstnd->next)
			fstnd = fstnd->next;
		fstnd->next = new_fstnd;
	}
	else
		*hd = new_fstnd;
	return (new_fstnd);
}



size_t print_list_str(const all_ *h)
{
	size_t i = 0;

	while (h)
	{
		_tspu(h->str ? h->str : "(null)");
		_tspu("\n");
		h = h->next;
		i++;
	}
	return (i);
}





int remove_fstnd_at_index(all_ **hd, unsigned int index)
{
	all_ *fstnd, *prev_fstnd;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);
	if (!index)
	{
		fstnd = *hd;
		*hd = (*hd)->next;
		free(fstnd->str);
		free(fstnd);
		return (1);
	}
	fstnd = *hd;
	while (fstnd)
	{
		if (i == index)
		{
			prev_fstnd->next = fstnd->next;
			free(fstnd->str);
			free(fstnd);
			return (1);
		}
		i++;
		prev_fstnd = fstnd;
		fstnd = fstnd->next;
	}
	return (0);
}



void avb_list(all_ **hd_ptr)
{
	all_ *fstnd, *next_fstnd, *hd;

	if (!hd_ptr || !*hd_ptr)
		return;
	hd = *hd_ptr;
	fstnd = hd;
	while (fstnd)
	{
		next_fstnd = fstnd->next;
		free(fstnd->str);
		free(fstnd);
		fstnd = next_fstnd;
	}
	*hd_ptr = NULL;
}



