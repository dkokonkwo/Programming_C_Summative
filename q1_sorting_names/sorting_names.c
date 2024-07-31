#include <stdio.h>
#include <stddef.h>
#include <string.h>

int sort_names(char *names[], void (*ptr)(char names[]));
int (*get_sort_func(char *s))(char *names[]);

/**
 * main - run programs / checks code
 *
 * Return: 0 on success
 */

int main()
{
int func;
char *names[100];

void (*fptr[2])(char *[]) = {get_sort_func, count_names};

printf("Enter 1 to sort names or 2 to print count number of names");
scanf("%d", &chooose_func);

fptr[func - 1](names);

return (0);
}


/**
 * get_sort_func - gets sorting order fxn
 * @s: sorting order
 * @names: input array
 *
 * Return: -1 on error
 */

int get_sort_func(char *names[])
{
char order[4];
printf("Enter 'asc' to sort in ascending and 'desc' to sort in descending");
scanf("%s", &order);

if (strcmp(order, "asc") == 0)
{

void (*f)(char *names[]);
if (strcmp(s, "asc") == 0)
{
f(;
}
else if (strcmp(s, "desc") == 0)
{
return desc_sort;
}
else
{
printf("Usage: 'asc for asending order, 'desc' for descending order");
exit(98);
}
}

void (*sort_names)(char *names[], void (*f)(char *names[]))
{
if (f == NULL)
{
return;
}
f(names);
}

/**
 * count_names - counts names in an array
 * @names: array of names
 *
 * Return: total num of names in array
 */

int count_names(char *names[])
{
int i;
while (*names)
{
i++;
names++;
}
return (i);
}

