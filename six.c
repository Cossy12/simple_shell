#include "shell.h"


size_t list_len(const a_l_l *n)
{
	size_t i = 0;

	while (n)
	{
		n = n->fwd;
		i++;
	}
	return (i);
}



char **a_l_lo_strings(a_l_l *fshd)
{
	a_l_l *nddd = fshd;
	size_t i = list_len(fshd), j;
	char **vfstin;
	char *str;

	if (!fshd || !i)
		return (NULL);
	vfstin = malloc(sizeof(char *) * (i + 1));
	if (!vfstin)
		return (NULL);
	for (i = 0; nddd; nddd = nddd->fwd, i++)
	{
		str = malloc(_lng_str_i(nddd->shdia) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(vfstin[j]);
			free(vfstin);
			return (NULL);
		}
		str = _co_py_s_tring(str, nddd->shdia);
		vfstin[i] = str;
	}
	vfstin[i] = NULL;
	return (vfstin);
}



size_t enabl_lrst(const a_l_l *h)
{
	size_t i = 0;

	while (h)
	{
		_outputxw(cnvt_no(h->munde, 10, 0));
		_outpu_ty(':');
		_outpu_ty(' ');
		_outputxw(h->shdia ? h->shdia : "(nil)");
		_outputxw("\n");
		h = h->fwd;
		i++;
	}
	return (i);
}



a_l_l *nd_acces_pn(a_l_l *nddd, char *fixpre, char c)
{
	char *p = NULL;

	while (nddd)
	{
		p = begi_ns(nddd->shdia, fixpre);
		if (p && ((c == -1) || (*p == c)))
			return (nddd);
		nddd = nddd->fwd;
	}
	return (NULL);
}



ssize_t access_nd(a_l_l *fshd, a_l_l *nddd)
{
	size_t i = 0;

	while (fshd)
	{
		if (fshd == nddd)
			return (i);
		fshd = fshd->fwd;
		i++;
	}
	return (-1);
}



