#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   int x;
   int y;
}point;


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
    point *p;
    point my_point;

    student kevin;
    strcpy(kevin.name, "Kevin");
    strcpy(kevin.id, "Eng18A00270y");
    kevin.age = 27;
    create_student(kevin);

    
    
    my_point.x = {.x=3, .y=7};
    
    p = &my_point;
    
    (*p).y = 98; /* p->y = 98; */
                /* my_point.y = 98; */
    printf("My_point y value: %d\n", p->y);



    return (0);
}




void create_student(student x)
{
    
    printf("Student's Name: \"%s\"\n", x.name);
    printf("Student ID: \"%s\"\n", x.id);
    printf("Students's age: %d.\n", x.age);

}
