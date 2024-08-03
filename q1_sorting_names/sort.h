#ifndef SORT_H
#define SORT_H

#include <stdio.h>

int sort_asc(char *names[]);
int sort_desc(char *names[]);
int count_names(char *names[], int (*f)(char *names[]));
int sort_names(char *names[], int (*f)(char *names[]));
int compare_asc(const void *a, const void *b);
int compare_desc(const void *a, const void *b);

#endif
