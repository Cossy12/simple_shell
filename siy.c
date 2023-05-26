#include "shell.h"




a_l_l *ne_nd_add(a_l_l **dhdd, const char *str, int num)
{
	a_l_l *fst_h_d;

	if (!dhdd)
		return (NULL);
	fst_h_d = malloc(sizeof(a_l_l));
	if (!fst_h_d)
		return (NULL);
	_set_memory((void *)fst_h_d, 0, sizeof(a_l_l));
	fst_h_d->munde = num;
	if (str)
	{
		fst_h_d->shdia = up_st_ing(str);
		if (!fst_h_d->shdia)
		{
			free(fst_h_d);
			return (NULL);
		}
	}
	fst_h_d->fwd = *dhdd;
	*dhdd = fst_h_d;
	return (fst_h_d);
}



a_l_l *more_nd(a_l_l **dhdd, const char *str, int num)
{
	a_l_l *vr_ndd, *d_nde;

	if (!dhdd)
		return (NULL);
	d_nde = *dhdd;
	vr_ndd = malloc(sizeof(a_l_l));
	if (!vr_ndd)
		return (NULL);
	_set_memory((void *)vr_ndd, 0, sizeof(a_l_l));
	vr_ndd->munde = num;
	if (str)
	{
		vr_ndd->shdia = up_st_ing(str);
		if (!vr_ndd->shdia)
		{
			free(vr_ndd);
			return (NULL);
		}
	}
	if (d_nde)
	{
		while (d_nde->fwd)
			d_nde = d_nde->fwd;
		d_nde->fwd = vr_ndd;
	}
	else
		*dhdd = vr_ndd;
	return (vr_ndd);
}



size_t l_sty(const a_l_l *h)
{
	size_t i = 0;

	while (h)
	{
		_outputxw(h->shdia ? h->shdia : "(nil)");
		_outputxw("\n");
		h = h->fwd;
		i++;
	}
	return (i);
}



int rm_node_a(a_l_l **dhdd, unsigned int first)
{
	a_l_l *d_nde, *cr_ndd_;
	unsigned int i = 0;

	if (!dhdd || !*dhdd)
		return (0);
	if (!first)
	{
		d_nde = *dhdd;
		*dhdd = (*dhdd)->fwd;
		free(d_nde->shdia);
		free(d_nde);
		return (1);
	}
	d_nde = *dhdd;
	while (d_nde)
	{
		if (i == first)
		{
			cr_ndd_->fwd = d_nde->fwd;
			free(d_nde->shdia);
			free(d_nde);
			return (1);
		}
		i++;
		cr_ndd_ = d_nde;
		d_nde = d_nde->fwd;
	}
	return (0);
}



void un_list_free(a_l_l **fst_hd)
{
	a_l_l *d_nde, *cr_ndd, *dhdd;

	if (!fst_hd || !*fst_hd)
		return;
	dhdd = *fst_hd;
	d_nde = dhdd;
	while (d_nde)
	{
		cr_ndd = d_nde->fwd;
		free(d_nde->shdia);
		free(d_nde);
		d_nde = cr_ndd;
	}
	*fst_hd = NULL;
}





