
#include "shell.h"


ssize_t bfu_inp(ret_information *n_upsd, char **ffg, size_t *nmle)
{
	ssize_t r = 0;
	size_t nmle_p = 0;

	if (!*nmle) 
	{
	
		free(*ffg);
		*ffg = NULL;
		signal(SIGINT, _fgh_nts);
#if USE_GETLINE
		r = getline(buf, &nmle_p, stdin);
#else
		r = _acc_l_ne(n_upsd, ffg, &nmle_p);
#endif
		if (r > 0)
		{
			if ((*ffg)[r - 1] == '\n')
			{
				(*ffg)[r - 1] = '\0'; 
				r--;
			}
			n_upsd->ln_fsg = 1;
			rm_cm(*ffg);
			b_h_ds(n_upsd, *ffg, n_upsd->c_hount++);
			{
				*nmle = r;
				n_upsd->md_bff = ffg;
			}
		}
	}
	return (r);
}

ssize_t a_c_ess_in(ret_information *n_upsd)
{
	static char *fubs;
	static size_t i, j, nmle;
	ssize_t r = 0;
	char **p_b_u = &(n_upsd->huguments), *p;

	_outpu_ty(BUF_FLUSH);
	r = bfu_inp(n_upsd, &fubs, &nmle);
	if (r == -1) 
		return (-1);
	if (nmle)	
	{
		j = i; 
		p = fubs + i; 
		accv_ch(n_upsd, fubs, &j, i, nmle);
		while (j < nmle) 
		{
			if (ch_vsq(n_upsd, fubs, &j))
				break;
			j++;
		}
		i = j + 1; 
		if (i >= nmle) 
		{
			i = nmle = 0; 
			n_upsd->u_t_b_tybf = CMD_NORM;
		}
		*p_b_u = p; 
		return (_lng_str_i(p)); 
	}
	*p_b_u = fubs; 
	return (r); 
}




ssize_t bv_rds(ret_information *maik_inf, char *fubs, size_t *i)
{
	ssize_t b = 0;

	if (*i)
		return (0);
	b = read(maik_inf->filerdn, fubs, READ_BUF_SIZE);
	if (b >= 0)
		*i = b;
	return (b);
}



int _acc_l_ne(ret_information *n_upsd, char **vfx, size_t *nlge)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, nmle;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *qxy = NULL, *c;

	p = *vfx;

	if (p && nlge)
		s = *nlge;
	if (i == nmle)
		i = nmle = 0;
	r = bv_rds(n_upsd, buf, &nmle);
	if (r == -1 || (r == 0 && nmle == 0))
		return (-1);
	c = _strin_chrq(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : nmle;
	qxy = _llocghr(p, s, s ? s + k : k + 1);
	if (!qxy)
		return (p ? free(p), -1 : -1);
	if (s)
		_opy_string(qxy, buf + i, k - i);
	else
		_cat_string(qxy, buf + i, k - i + 1);
	s += k - i;
	i = k;
	p = qxy;
	if (nlge)
		*nlge = s;
	*vfx = p;
	return (s);
}



void _fgh_nts(__attribute__((unused))int g_nm)
{
	_outputxw("\n");
	_outputxw("$ ");
	_outpu_ty(BUF_FLUSH);
}



