#include <stdio.h>

struct student
{
    int id;
    char name[20];
    float marks;
};

int main()
{
    struct student s1 = {1, "Darshan", 89.5};
    printf("Id: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("marks: %.2f\n", s1.marks);
    return 0;
}
