#include <stdio.h>

int main()
{
    int matA[3][3], matB[3][3], result[3][3], diff[3][3];

    printf("Enter elements of Matrix A (3x3):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter elements of Matrix B (3x3):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    printf("Resultant Matrix (R = A x B):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            diff[i][j] = matA[i][j] - result[i][j];
        }
    }

    printf("Subtracted Matrix (S = A - R):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}
