#include "shell.h"


int _lng_str_i(char *n)
{
	int c = 0;

	if (!n)
		return (0);
	while (*n++)
		c++;
	return (c);
}



int _s_t_i_ng(char *rd, char *fd33)
{
	while (*rd && *fd33)
	{
		if (*rd != *fd33)
			return (*rd - *fd33);
		rd++;
		fd33++;
	}
	if (*rd == *fd33)
		return (0);
	else
		return (*rd < *fd33 ? -1 : 1);
}



char *begi_ns(const char *q_stck, const char *pnts)
{
	while (*pnts)
		if (*pnts++ != *q_stck++)
			return (NULL);
	return ((char *)q_stck);
}


char *_c_a_t_string(char *fn_pts, char *origin)
{
	char *ret = fn_pts;

	while (*fn_pts)
		fn_pts++;
	while (*origin)
		*fn_pts++ = *origin++;
	*fn_pts = *origin;
	return (ret);
}



