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
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
extern char **environ;


typedef struct a___l
{
	int num;
	char *str;
	struct a___l *next;
} a_l_l;



typedef struct inf
{
	char *arg;
	char **sil;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	a_l_l *env;
	a_l_l *prev_e_v;
	a_l_l *name;
	char **viron;
	int env_dfed;


	int lvl;



	int filrd;
	char **fdg_buf; 
	int dffg__dfg_type; 


    
	int histcount;
} main_if;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}












/* five.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);











/* first */
int rdfl(main_if *);
int val_is(char, char *);
int val_nm(int);
int valu_sh(char *);








/* sec */
int quit_ex(main_if *);
int _entr_dir(main_if *);
int _assist(main_if *);











/* three */
int istory_fl(main_if *);
int name_usr(main_if *);















/* four.c */
char *ftch_env(main_if *, const char *);
int env_fl(main_if *);
int rn_env(main_if *);
int psv_env(main_if *);
int fill_env(main_if *);


















#endif




