#include <stdio.h>

int main()
{
    int numRows;

    printf("Enter the number of rows for the upper half of the diamond: ");
    scanf("%d", &numRows);

    for (int i = 1; i <= numRows; i++)
    {
        for (int j = i; j < numRows; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = numRows - 1; i >= 1; i--)
    {
        for (int j = numRows; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
