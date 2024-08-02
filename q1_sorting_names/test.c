// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

void sort_asc(char *names[]);
void sort_desc(char *names[]);
void count_names(char *names[], void (*f)(char *names[]));
void sort_names(char *names[], void (*f)(char *names[]));
typedef void (*fptr)(char *names[], void (*f)(char *names[]));


int main() {
    // Write C code here
    int i;
    char sort_by[4];
    char *names[100] = {
        "David",
        "Steve",
        "John",
        "Jonah"
    };
    fptr func[] = {sort_names, count_names};
    
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
            func[0](names, sort_asc);
            return (0);
        }
        else if (strcmp(sort_by, "desc") == 0)
        {
            func[0](names, sort_desc);
            return (0);
        }
        else
        {
            printf("Invalid input.Type 'asc' to sort in ascending or 'desc' for descending.\n");
            return (-1);
        }
        
    }
    else if (i == 2) {
        func[1](names, NULL);  // count_names doesn't require a second function pointer argument
    } else {
        printf("Invalid input, please type 1 or 2\n");
        return -1;
    }
    

    return 0;
}

void sort_names(char *names[], void (*f)(char *names[]))
{
    if (f == NULL)
    {
        return;
    }
    f(names);
}

void count_names(char *names[], void (*f)(char *names[]))
{
    int n = 0;
    while(*names)
    {
        n++;
        names++;
    }
    printf("There are %d names in the array", n);
    
}

void sort_asc(char *names[])
{
    printf("Nice");
}

void sort_desc(char *names[])
{
    printf("Noice");
}
