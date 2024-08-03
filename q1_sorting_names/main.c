#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 100

typedef int (*fptr)(char *names[], int (*f)(char *names[]));

int main(int argc, char *argv[]) {
    int i, result;
    char sort_by[4];
    char *names[MAX_NAMES];
    FILE *file;
    fptr func[] = {sort_names, count_names};

    if (argc != 2)
    {
	printf("Usage: %s <filename>\n", argv[0]);
	return (-1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
	printf("Error opening file");
	return (-1);
    }

    int count = 0;
    char buffer[MAX_NAME_LENGTH];
    while (fgets(buffer, MAX_NAME_LENGTH, file) && count < MAX_NAMES)
    {
	buffer[strcspn(buffer, "\n")] = '\0';

	names[count] = malloc(strlen(buffer) + 1);
	if (names[count] == NULL)
	{
	    perror("Error allocating memory");
	    fclose(file);
	    return (-1);
	}
	strcpy(names[count], buffer);
	count++;
    }

    fclose(file);

    printf("Type 1 to sort the array or 2 to count the number of names in the array:\n ");
    if (scanf("%d", &i) != 1)
    {
        printf("Invalid input please type 1 or 2\n");
        return (-1);
    }
    if (i == 1)
    {
        printf("Type 'asc' to sort in ascending or 'desc' for descending: ");
        if(scanf("%s", sort_by) != 1)
        {
            printf("Invalid input.Type 'asc' to sort in ascending or 'desc' for descending.\n");
            return (-1);
        }

        if (strcmp(sort_by, "asc") == 0)
        {
            result = func[0](names, sort_asc);
	    for (i = 0; i < count; i++)
	    {
		printf("%s\n", names[i]);
		free(names[i]);
	    }
            return (result);
        }
        else if (strcmp(sort_by, "desc") == 0)
        {
            result = func[0](names, sort_desc);
	    for (i = 0; i < count; i++)
            {
                printf("%s\n", names[i]);
                free(names[i]);
            }
            return (result);
        }
        else
        {
            printf("Invalid input.Type 'asc' to sort in ascending or 'desc' for descending.\n");
            return (-1);
        }

    }
    else if (i == 2) {
        result = func[1](names, NULL);
	printf("There are %d names in file.\n", result);
      	return (result);
    } else {
        printf("Invalid input, please type 1 or 2\n");
        return -1;
    }


    return 0;
}
