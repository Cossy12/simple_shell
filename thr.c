#include "shell.h"


char *_set_memory(char *w, char v, unsigned int n)
{
	unsigned int g;

	for (g = 0; g < n; g++)
		w[g] = v;
	return (w);
}

void ree_fre(char **bx)
{
	char **m = bx;

	if (!bx)
		return;
	while (*bx)
		free(*bx++);
	free(m);
}



void *_llocghr(void *vfs, unsigned int ny_lng, unsigned int size_x_)
{
	char *d;

	if (!vfs)
		return (malloc(size_x_));
	if (!size_x_)
		return (free(vfs), NULL);
	if (size_x_ == ny_lng)
		return (vfs);
	d = malloc(size_x_);
	if (!d)
		return (NULL);
	ny_lng = ny_lng < size_x_ ? ny_lng : size_x_;
	while (ny_lng--)
		d[ny_lng] = ((char *)vfs)[ny_lng];
	free(vfs);
	return (d);
}



