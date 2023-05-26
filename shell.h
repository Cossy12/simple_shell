#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".history"
#define HIST_MAX	4096
extern char **environ;

typedef struct all_ll
{
	int munde;
	char *shdia;
	struct all_ll *fwd;
} a_l_l;

typedef struct variabiles
{
	char *huguments;
	char **aguments_s;
	char *fllow;
	int gramuent;
	unsigned int cntlne_;
	int mn_e_rsd;
	int ln_fsg;
	char *n_ma;
	a_l_l *venf;
	a_l_l *shhistory;
	a_l_l *n_ame;
	char **vironment;
	int venv_und;
	int lvlsh;
	char **md_bff; 
	int u_t_b_tybf; 
	int filerdn;
	int c_hount;
} ret_information;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


typedef struct tbl_sq
{
	char *ypes;
	int (*func)(ret_information *);
} tnl_tab;


int haal(ret_information *, char **);
int loc_a_t(ret_information *);
void find_cmd(ret_information *);
void c_m_adddd(ret_information *);

int command_cd(ret_information *, char *);
char *characters_ne_d(char *, int, int);
char *fll_w_he(ret_information *, char *, char *);

int loophsh(char **);

void _outpse(char *);
int _outputfsd(char);
int _ouhtput(char c, int fd);
int _otyput(char *str, int fd);

int _lng_str_i(char *);
int _s_t_i_ng(char *, char *);
char *begi_ns(const char *, const char *);
char *_c_a_t_string(char *, char *);

char *_co_py_s_tring(char *, char *);
char *up_st_ing(const char *);
void _outputxw(char *);
int _outpu_ty(char);

char *_cat_string(char *, char *, int);
char *_opy_string(char *, char *, int);
char *_strin_chrq(char *, char);

char **v_o_column(char *, char *);
char **strtow2(char *, char);

char *_set_memory(char *, char, unsigned int);
void ree_fre(char **);
void *_llocghr(void *, unsigned int, unsigned int);

int ref_ee(void **);

int main_interconnection(ret_information *);
int value_is(char, char *);
int _i_s_main(int);
int _i_s_fn(char *);

int _prov_errors(char *);
void show_issue(ret_information *, char *);
int shw_a_l(int, int);
char *cnvt_no(long int, int, int);
void rm_cm(char *);

int _escapade(ret_information *);
int _nav_cd(ret_information *);
int _myhelp(ret_information *);

int _historia(ret_information *);
int _name_my(ret_information *);

ssize_t a_c_ess_in(ret_information *);
int _acc_l_ne(ret_information *, char **, size_t *);
void _fgh_nts(int);

void rm_info_rm(ret_information *);
void info_s_e(ret_information *, char **);
void info_f_r_e(ret_information *, int);

char *_sele_tenv(ret_information *, const char *);
int _i_env(ret_information *);
int _curr_env(ret_information *);
int un_env(ret_information *);
int fill_env(ret_information *);

char **fetch_env_(ret_information *);
int _declunenv(ret_information *, char *);
int _act_env(ret_information *, char *, char *);

char *file_ishist(ret_information *info);
int v_b_dfgh(ret_information *info);
int ac_h_i_s(ret_information *info);
int b_h_ds(ret_information *info, char *buf, int linecount);
int rnm_hs(ret_information *info);

a_l_l *ne_nd_add(a_l_l **, const char *, int);
a_l_l *more_nd(a_l_l **, const char *, int);
size_t l_sty(const a_l_l *);
int rm_node_a(a_l_l **, unsigned int);
void un_list_free(a_l_l **);

size_t list_len(const a_l_l *);
char **a_l_lo_strings(a_l_l *);
size_t enabl_lrst(const a_l_l *);
a_l_l *nd_acces_pn(a_l_l *, char *, char);
ssize_t access_nd(a_l_l *, a_l_l *);

int ch_vsq(ret_information *, char *, size_t *);
void accv_ch(ret_information *, char *, size_t *, size_t, size_t);
int a_l_newname(ret_information *);
int variables_nw(ret_information *);
int ting_rpsd(char **, char *);
#endif



