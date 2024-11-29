#include <stdio.h>

struct Firm
{
    char firmName[50];
    int foundationYear;
    char deptNames[5][50];
};

int main()
{
    struct Firm firm;
    int departmentCount;

    printf("Enter firm name: ");
    scanf("%s", firm.firmName);
    
    printf("Enter year of foundation: ");
    scanf("%d", &firm.foundationYear);

    do
    {
        printf("Enter number of departments (1 to 5): ");
        scanf("%d", &departmentCount);
    } while (departmentCount < 1 || departmentCount > 5);

    printf("Enter names of %d departments:\n", departmentCount);
    for (int i = 0; i < departmentCount; i++)
    {
        printf("Department %d: ", i + 1);
        scanf("%s", firm.deptNames[i]);
    }

    printf("\n[Company Details]\n");
    printf("Name: %s\n", firm.firmName);
    printf("Year of Foundation: %d\n", firm.foundationYear);
    printf("Departments:\n");
    for (int i = 0; i < departmentCount; i++)
    {
        printf("%d > %s\n", i + 1, firm.deptNames[i]);
    }

    return 0;
}
