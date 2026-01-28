#include <stdio.h>
#include <stdlib.h>

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
    struct Employee *emp;
    int n, i;
    float gross_salary;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Dynamic memory allocation using malloc
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee details
    for (i = 0; i < n; i++)
    {

        // emp[0].id = 101;           // array style
        // (*(emp + 1)).id = 102;     // dereference style
        // (emp + 2)->id = 103;       // pointer arrow style

        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &(emp + i)->emp_id);

        printf("Employee Name: ");
        scanf(" %[^\n]", (emp + i)->emp_name);

        printf("Basic Salary: ");
        scanf("%f", &(emp + i)->basic_salary);

        printf("HRA: ");
        scanf("%f", &(emp + i)->hra);

        printf("DA: ");
        scanf("%f", &(emp + i)->da);
    }

    // Display employee data with gross salary
    printf("\n-------------------------------------------------------------\n");
    printf("Emp_ID\tEmp_Name\tBasic\tHRA\tDA\tGross_Salary\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        gross_salary = (emp + i)->basic_salary + (emp + i)->hra + (emp + i)->da;
        printf("%d\t%-10s\t%.2f\t%.2f\t%.2f\t%.2f\n",
               (emp + i)->emp_id,
               (emp + i)->emp_name,
               (emp + i)->basic_salary,
               (emp + i)->hra,
               (emp + i)->da,
               gross_salary);
    }

    // Optional: resize memory using realloc
    int new_size;
    printf("\nDo you want to add more employees? Enter new total size (or 0 to skip): ");
    scanf("%d", &new_size);

    if (new_size > n)
    {
        emp = (struct Employee *)realloc(emp, new_size * sizeof(struct Employee));
        if (emp == NULL)
        {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        // Enter new employee details
        for (i = n; i < new_size; i++)
        {
            printf("\nEnter details for Employee %d:\n", i + 1);
            printf("Employee ID: ");
            scanf("%d", &(emp + i)->emp_id);

            printf("Employee Name: ");
            scanf(" %[^\n]", (emp + i)->emp_name);

            printf("Basic Salary: ");
            scanf("%f", &(emp + i)->basic_salary);

            printf("HRA: ");
            scanf("%f", &(emp + i)->hra);

            printf("DA: ");
            scanf("%f", &(emp + i)->da);
        }

        // Updated employee list
        printf("\nUpdated Employee List:\n");
        printf("-------------------------------------------------------------\n");
        printf("Emp_ID\tEmp_Name\tBasic\tHRA\tDA\tGross_Salary\n");
        printf("-------------------------------------------------------------\n");

        for (i = 0; i < new_size; i++)
        {
            gross_salary = (emp + i)->basic_salary + (emp + i)->hra + (emp + i)->da;
            printf("%d\t%-10s\t%.2f\t%.2f\t%.2f\t%.2f\n",
                   (emp + i)->emp_id,
                   (emp + i)->emp_name,
                   (emp + i)->basic_salary,
                   (emp + i)->hra,
                   (emp + i)->da,
                   gross_salary);
        }

        n = new_size; // update original size
    }

    // Free dynamically allocated memory
    free(emp);

    return 0;
}
