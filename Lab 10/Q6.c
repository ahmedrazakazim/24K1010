#include <stdio.h>
#include <string.h>

typedef struct
{
    char packageName[50];
    char destination[50];
    int duration;
    float cost;
    int seats;
} Package;

void displayPackages(Package packages[], int count)
{
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Package %d:\n", i + 1);
        printf("  > Name: %s\n", packages[i].packageName);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f\n", packages[i].cost);
        printf("  Seats: %d\n\n", packages[i].seats);
    }
}

void bookPackage(Package packages[], int count)
{
    char packageName[50];
    printf("\nEnter the package name you want to book: ");
    fgets(packageName, sizeof(packageName), stdin);
    packageName[strcspn(packageName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(packages[i].packageName, packageName) == 0)
        {
            found = 1;
            if (packages[i].seats > 0)
            {
                packages[i].seats--;
                printf("\nBooking confirmed for package: %s\n", packages[i].packageName);
            }
            else
            {
                printf("\nSorry, no seats available for package: %s\n", packages[i].packageName);
            }
            break;
        }
    }

    if (!found)
    {
        printf("\nPackage not found.\n");
    }
}

int main()
{
    Package packages[999];

    int numPackages;
    printf("Enter the number of travel packages: ");
    scanf("%d", &numPackages);
    getchar();

    for (int i = 0; i < numPackages; i++)
    {
        printf("\nEnter details for package %d:\n", i + 1);

        printf("Package name: ");
        fgets(packages[i].packageName, sizeof(packages[i].packageName), stdin);
        packages[i].packageName[strcspn(packages[i].packageName, "\n")] = 0;

        printf("Destination: ");
        fgets(packages[i].destination, sizeof(packages[i].destination), stdin);
        packages[i].destination[strcspn(packages[i].destination, "\n")] = 0;

        printf("Duration (in days): ");
        scanf("%d", &packages[i].duration);
        getchar();

        printf("Cost: ");
        scanf("%f", &packages[i].cost);
        getchar();

        printf("Seats available: ");
        scanf("%d", &packages[i].seats);
        getchar();
    }

    printf("\nWelcome to the Travel Booking System!\n");
    displayPackages(packages, numPackages);
    bookPackage(packages, numPackages);

    printf("\nUpdated Package List After Booking:\n");
    displayPackages(packages, numPackages);

    return 0;
}
