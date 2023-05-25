#include "shell.h"




char *_set(char *vs, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		vs[i] = b;
	return (vs);
}





void availablee(char **nb)
{
	char **a = nb;

	if (!nb)
		return;
	while (*nb)
		free(*nb++);
	free(a);
}



void *_realloc(void *quat_alw, unsigned int pre_qua, unsigned int cur_qua)
{
	char *plat;

	if (!quat_alw)
		return (malloc(cur_qua));
	if (!cur_qua)
		return (free(quat_alw), NULL);
	if (cur_qua == pre_qua)
		return (quat_alw);
	plat = malloc(cur_qua);
	if (!plat)
		return (NULL);
	pre_qua = pre_qua < cur_qua ? pre_qua : cur_qua;
	while (pre_qua--)
		plat[pre_qua] = ((char *)quat_alw)[pre_qua];
	free(quat_alw);
	return (plat);
}



