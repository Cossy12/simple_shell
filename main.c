#include "shell.h"


int main(int nhg, char **ed)
{
	ret_information m_nh[] = { INFO_INIT };
	int kj = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (kj)
		: "r" (kj));

	if (nhg == 2)
	{
		kj = open(ed[1], O_RDONLY);
		if (kj == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_outpse(ed[0]);
				_outpse(": 0: Can't open ");
				_outpse(ed[1]);
				_outputfsd('\n');
				_outputfsd(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		m_nh->filerdn = kj;
	}
	fill_env(m_nh);
	ac_h_i_s(m_nh);
	haal(m_nh, ed);
	return (EXIT_SUCCESS);
}




