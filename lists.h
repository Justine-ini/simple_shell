#ifndef _LISTS_
#define _LISTS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;

void _prompt(void);
char *_getline(void);
char **strtok_array(char *new_line, char *delimiters);
char *_which(char *string);
int _execute(char *path, char **string);
void _signal_handler(int signal);
void free_string_array(char **array);
char *search_path(char *command, char *directory);
void free_string_array(char **array);
void print_environment(void);
int _atoi(char *s);
void exit_shell(char **string, char *new_line);
char *_strtok(char *line, char *delim);
int cd_command(char *directory);

#endif
