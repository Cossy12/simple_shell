#include "shell.h"




char **v_o_column(char *vasting, char *d)
{
	int i, j, k, m, vxls_dwod = 0;
	char **s;

	if (vasting == NULL || vasting[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; vasting[i] != '\0'; i++)
		if (!value_is(vasting[i], d) && (value_is(vasting[i + 1], d) || !vasting[i + 1]))
			vxls_dwod++;
	if (vxls_dwod == 0)
		return (NULL);
	s = malloc((1 + vxls_dwod) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < vxls_dwod; j++)
	{
		while (value_is(vasting[i], d))
			i++;
		k = 0;
		while (!value_is(vasting[i + k], d) && vasting[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = vasting[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}


char **vastingtow2(char *vasting, char d)
{
	int b, j, q, r, vxls_dwod = 0;
	char **v;

	if (vasting == NULL || vasting[0] == 0)
		return (NULL);
	for (b = 0; vasting[b] != '\0'; b++)
		if ((vasting[b] != d && vasting[b + 1] == d) ||
		    (vasting[b] != d && !vasting[b + 1]) || vasting[b + 1] == d)
			vxls_dwod++;
	if (vxls_dwod == 0)
		return (NULL);
	v = malloc((1 + vxls_dwod) * sizeof(char *));
	if (!v)
		return (NULL);
	for (b = 0, j = 0; j < vxls_dwod; j++)
	{
		while (vasting[b] == d && vasting[b] != d)
			b++;
		q = 0;
		while (vasting[b + q] != d && vasting[b + q] && vasting[b + q] != d)
			q++;
		v[j] = malloc((q + 1) * sizeof(char));
		if (!v[j])
		{
			for (q = 0; q < j; q++)
				free(v[q]);
			free(v);
			return (NULL);
		}
		for (r = 0; r < q; r++)
			v[j][r] = vasting[b++];
		v[j][r] = 0;
	}
	v[j] = NULL;
	return (v);
}



