#include "shell.h"


int ref_ee(void **memview)
{
	if (memview && *memview)
	{
		free(*memview);
		*memview = NULL;
		return (1);
	}
	return (0);
}



