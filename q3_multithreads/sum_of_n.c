#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10

/**
 * struct ThreadData - structure for thread data
 * @start: starting integer
 * @end: ending integer
 */

typedef struct
{
long start;
long end;
} ThreadData;

/**
 * add_range - adds numbers with a range
 * @arg: threadData type with values
 *
 * Return: sum
 */
void *add_range(void *arg)
{
long i, sum = 0;
ThreadData *data = (ThreadData *) arg;
for (i = data->start; i <= data->end; i++)
{
sum += i;
}

long *result = (long *) malloc(sizeof(long));
*result = sum;

free(data);
return (void *) result;
}

/**
 * main - sums up value from 0 to n
 * Return: 0 and suceess, -1 on error
 */
int main(void)
{
pthread_t threads[NUM_THREADS];
long n, range, start, end;
long total_sum = 0;
int i;
printf("Enter input value number (greater than 1000): \n");
if (scanf("%ld", &n) != 1 || n <= 1000)
{
printf("Invalid input. Number must be greater than 1000\n");
return(-1);
}

range = n / NUM_THREADS;
start = 0;
end = range;

for (i = 0; i < NUM_THREADS; i++)
{
ThreadData *data = (ThreadData *) malloc(sizeof(ThreadData));
data->start = start;
data->end = (i == NUM_THREADS - 1) ? n : end;

if (pthread_create(&threads[i], NULL, add_range, (void *) data) != 0)
{
printf("Error creating thread %d\n", i);
return (-1);
}

start = end + 1;
end += range;
}

for (i = 0; i < NUM_THREADS; i++)
{
long *result;
if (pthread_join(threads[i], (void **)&result) != 0)
{
printf("Error joining thread %d\n", i);
return (-1);
}
total_sum += *result;
free(result);
}

printf("The sum of %ld is %ld\n", n, total_sum);
return(0);
}
