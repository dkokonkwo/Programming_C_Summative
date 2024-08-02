#include <stdio.h>
#include <stdlib.h>

/**
 * struct Student - structure for a student
 * @name: name of student
 * @c_prog: score for C Programming course
 * @mobile: mobile dev course score
 * @comm: Communication course score
 */

typedef struct
{
char name[30];
int c_prog;
int mobile;
int comm;
} Student;

/**
 * create_student - creates and stores new student record
 * @stud: student structure
 *
 * Return: 0 on success and -1 on error
 */

int create_student(Student stud, char *filename)
{
FILE *file;
file = fopen(filename, "ab");
if (file == NULL)
{
printf("Error opening file.\n");
return (-1);
}
fwrite(&stud, sizeof(Student), 1, file);
fclose(file);
return (0);
}

/**
 * main - call function to create and store n students records
 * Return: 0 on success, -1 or error
 */

int main(void)
{
int n, i;
Student stud;

printf("Enter number of records to create: ");
if (scanf("%d", &n) != 1 || n <= 0)
{
printf("Invalid number of records.\n");
return (-1);
}

for (i = 0; i < n; i++)
{
printf("Create new student record:\n");
printf("Full name: ");
scanf("%s", stud.name);
while (getchar() != '\n');
printf("Programming in C score (/100): ");
if (scanf("%d", &stud.c_prog) != 1 || stud.c_prog < 0 || stud.c_prog > 100)
{
printf("Invalid score. Please enter a number between 0 and 100.\n");
return (-1);
}
while (getchar() != '\n');
printf("Mobile App Development score (/100): ");
if (scanf("%d", &stud.mobile) != 1 || stud.mobile < 0 || stud.mobile > 100)
{
printf("Invalid score. Please enter a number between 0 and 100.\n");
return (-1);
}
while (getchar() != '\n');
printf("Communications Course score (/100): ");
if (scanf("%d", &stud.comm) != 1 || stud.comm < 0 || stud.comm > 100)
{
printf("Invalid score. Please enter a number between 0 and 100.\n");
return (-1);
}
while (getchar() != '\n');
if (create_student(stud, "students.bin") == -1)
{
printf("Error creating student record");
return (-1);
}
}

printf("Records created and saved!\n");
return (0);
}
