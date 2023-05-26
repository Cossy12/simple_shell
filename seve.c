#include "shell.h"




char *file_ishist(ret_information *bnifo)
{
	char *fu_b_bff, *dir;

	dir = _sele_tenv(bnifo, "HOME=");

	if (!dir)
		return (NULL);
	fu_b_bff = malloc(sizeof(char) * (_lng_str_i(dir) + _lng_str_i(HIST_FILE) + 2));
	if (!fu_b_bff)
		return (NULL);
	fu_b_bff[0] = 0;
	_co_py_s_tring(fu_b_bff, dir);
	_c_a_t_string(fu_b_bff, "/");
	_c_a_t_string(fu_b_bff, HIST_FILE);
	return (fu_b_bff);
}



int v_b_dfgh(ret_information *bnifo)
{
	ssize_t fd;
	char *fna_nm = file_ishist(bnifo);

	a_l_l *dnddes = NULL;

	if (!fna_nm)
		return (-1);
	fd = open(fna_nm, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fna_nm);
	if (fd == -1)
		return (-1);
	for (dnddes = bnifo->shhistory; dnddes; dnddes = dnddes->fwd)
	{
		_otyput(dnddes->shdia, fd);
		_ouhtput('\n', fd);
	}
	_ouhtput(BUF_FLUSH, fd);
	close(fd);
	return (1);
}



int ac_h_i_s(ret_information *bnifo)
{
	int i, fn_endeh = 0, cnt_lin = 0;
	ssize_t fd, hjghgs_t, en_fs = 0;
	struct stat st;
	char *fu_b_bff = NULL, *fna_nm = file_ishist(bnifo);

	if (!fna_nm)
		return (0);
	fd = open(fna_nm, O_RDONLY);
	free(fna_nm);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		en_fs = st.st_size;
	if (en_fs < 2)
		return (0);
	fu_b_bff = malloc(sizeof(char) * (en_fs + 1));
	if (!fu_b_bff)
		return (0);
	hjghgs_t = read(fd, fu_b_bff, en_fs);
	fu_b_bff[en_fs] = 0;
	if (hjghgs_t <= 0)
		return (free(fu_b_bff), 0);
	close(fd);
	for (i = 0; i < en_fs; i++)
		if (fu_b_bff[i] == '\n')
		{
			fu_b_bff[i] = 0;
			b_h_ds(bnifo, fu_b_bff + fn_endeh, cnt_lin++);
			fn_endeh = i + 1;
		}
	if (fn_endeh != i)
		b_h_ds(bnifo, fu_b_bff + fn_endeh, cnt_lin++);
	free(fu_b_bff);
	bnifo->c_hount = cnt_lin;
	while (bnifo->c_hount-- >= HIST_MAX)
		rm_node_a(&(bnifo->shhistory), 0);
	rnm_hs(bnifo);
	return (bnifo->c_hount);
}



int b_h_ds(ret_information *bnifo, char *fu_b_bff, int cnt_lin)
{
	a_l_l *dnddes = NULL;

	if (bnifo->shhistory)
		dnddes = bnifo->shhistory;
	more_nd(&dnddes, fu_b_bff, cnt_lin);
	if (!bnifo->shhistory)
		bnifo->shhistory = dnddes;
	return (0);
}



int rnm_hs(ret_information *bnifo)
{
	a_l_l *dnddes = bnifo->shhistory;
	int i = 0;

	while (dnddes)
	{
		dnddes->munde = i++;
		dnddes = dnddes->fwd;
	}
	return (bnifo->c_hount = i);
}



