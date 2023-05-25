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
#define HIST_FILE
#define HIST_MAX	4096

typedef struct all__
{
	int num;
	char *str;
	struct all__ *next;
} all_;

typedef struct passinfo
{
	char *grv;
	char **grvv;

	unsigned int coun_ted;
	char *fr_name;


	// int readfd;
	int fr;






} main_fl;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}




void _ts(char *);


int _har(char);



int fkpt(char c, int fd);


int fkpts(char *str, int fd);



int _lenstr(char *);



int _strcmp(char *, char *);


char *ignss_with(const char *, const char *);



char *_catstr(char *, char *);





void _tspu(char *);



int _chrs(char);



char *_set(char *, char, unsigned int);


void availablee(char **);


int vl_print(int, int);


char *_stringupup(const char *);





#endif



