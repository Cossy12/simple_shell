#include "shell.h"


int quit_ex(main_if *ifl_av)
{
	int quit_ch;

	if (ifl_av->sil[1])  
	{
		quit_ch = _errord(ifl_av->sil[1]);
		if (quit_ch == -1)
		{
			ifl_av->lvl = 2;
			print_error(ifl_av, "INACCURATE  number: ");
			_eputs(ifl_av->sil[1]);
			_eputchar('\n');
			return (1);
		}
		ifl_av->err_num = _errord(ifl_av->sil[1]);
		return (-2);
	}
	ifl_av->err_num = -1;
	return (-2);
}

int _entr_dir(main_if *ifl_av)
{
	char *s, *dir, bfed[1024];
	int chax;

	s = getcwd(bfed, 1024);
	if (!s)
		_puts("TODO: >> failure msg here<<\n");
	if (!ifl_av->sil[1])
	{
		dir = _getenv(ifl_av, "Home=");
		if (!dir)
			chax = 
				chdir((dir = _getenv(ifl_av, "pwd=")) ? dir : "/");
		else
			chax = chdir(dir);
	}
	else if (_strcmp(ifl_av->sil[1], "-") == 0)
	{
		if (!_getenv(ifl_av, "prepwd="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(ifl_av, "prepwd=")), _putchar('\n');
		chax = 
			chdir((dir = _getenv(ifl_av, "prepwd=")) ? dir : "/");
	}
	else
		chax = chdir(ifl_av->sil[1]);
	if (chax == -1)
	{
		print_error(ifl_av, "can't find directory to ");
		_eputs(ifl_av->sil[1]), _eputchar('\n');
	}
	else
	{
		_setenv(ifl_av, "prepwd", _getenv(ifl_av, "pwd="));
		_setenv(ifl_av, "pwd", getcwd(bfed, 1024));
	}
	return (0);
}

int _assist(main_if *ifl_av)
{
	char **argm_rray;

	argm_rray = ifl_av->sil;
	_puts("Fn not implemented \n");
	if (0)
		_puts(*argm_rray); 
	return (0);
}



