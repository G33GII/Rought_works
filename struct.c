#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    char name[50];
    char id[50];
    int age;
    int grades[5];
}student;

void create_student(student x);

int main(void)
{

    student kevin;
    strcpy(kevin.name, "Kevin");
    strcpy(kevin.id, "Eng18A00270y");
    kevin.age = 27;

    create_student(kevin);
    return (0);
}




void create_student(student x)
{
    
    printf("Student's Name: \"%s\"\n", x.name);
    printf("Student ID: \"%s\"\n", x.id);
    printf("Students's age: %d.\n", x.age);

}
