#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * sort_names - sort names in an array in chosen order
 * @names: array of names
 * @f: callback function for sorting names
 */
int sort_names(char *names[], int (*f)(char *names[]))
{
    int n;
    if (f == NULL)
    {
        return (-1);
    }
    n = f(names);
    return (n);
}

/**
 * count_names - prints number of names in an array
 * @names: array of names
 * @f: callback funcition is not used
 */
int count_names(char *names[], int (*f)(char *names[]))
{
    int n = 0;
    while(*names)
    {
        n++;
        names++;
    }
    return (n);
}


/**
 * compare_asc - compares in asencding order
 * @a: string 1
 * @b: string 2
 */
int compare_asc(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * compare_desc - compares in desencding order
 * @a: string 1
 * @b: string 2
 */
int compare_desc(const void *a, const void *b)
{
    return strcmp(*(const char **)b, *(const char **)a);
}


/**
 * sort_asc - sorts array in ascending order
 * @names: array of names
 */
int sort_asc(char *names[])
{
int size = count_names(names, NULL);
qsort(names, size, sizeof(char *), compare_asc);
printf("Names in Ascending Order:\n");
return (0);
}

/**
 * sort_desc - sorts array in descending order
 * @names: array of names
 */
int sort_desc(char *names[])
{
int size = count_names(names, NULL);
qsort(names, size, sizeof(char *), compare_desc);
printf("Names in Descending Order:\n");
return (0);
}

