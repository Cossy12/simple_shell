#include "shell.h"


int efreee(void **qwe)
{
	if (qwe && *qwe)
	{
		free(*qwe);
		*qwe = NULL;
		return (1);
	}
	return (0);
}



