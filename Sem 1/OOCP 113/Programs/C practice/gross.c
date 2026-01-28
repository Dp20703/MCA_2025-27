#include <stdio.h>

#define MAX 100 // maximum number of employees

// Structure definition
struct Employee
{
    int emp_id;
    char emp_name[50];
    float basic_salary;
    float hra;
    float da;
};

int main()
{
    struct Employee emp[MAX];
    int n, i;
    float gross_salary;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Input employee details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Employee Name: ");
        scanf(" %[^\n]", emp[i].emp_name); // accepts full name with spaces

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA: ");
        scanf("%f", &emp[i].hra);

        printf("DA: ");
        scanf("%f", &emp[i].da);
    }

    // Display employee data with gross salary
    printf("\n-------------------------------------------------------------\n");
    printf("Emp_ID\tEmp_Name\tBasic\tHRA\tDA\tGross_Salary\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        gross_salary = emp[i].basic_salary + emp[i].hra + emp[i].da;
        printf("%d\t%-10s\t%.2f\t%.2f\t%.2f\t%.2f\n",
               emp[i].emp_id,
               emp[i].emp_name,
               emp[i].basic_salary,
               emp[i].hra,
               emp[i].da,
               gross_salary);
    }

    return 0;
}
