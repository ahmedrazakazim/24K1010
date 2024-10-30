#include <stdio.h>

int main()
{
    int m[3][3];

    printf("Enter the elements of the 3x3 matrix:\n");
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            scanf("%d", &m[r][c]);
        }
    }

    for (int r = 0; r < 3; r++)
    {
        int minNum = m[r][0];
        int minColIdx = 0;

        for (int c = 1; c < 3; c++)
        {
            if (m[r][c] < minNum)
            {
                minNum = m[r][c];
                minColIdx = c;
            }
        }

        int maxVal = m[0][minColIdx];
        for (int k = 0; k < 3; k++)
        {
            if (m[k][minColIdx] > maxVal)
            {
                maxVal = m[k][minColIdx];
            }
        }

        if (minNum == maxVal)
        {
            printf("Saddle point found: %d at position (%d, %d)\n", minNum, r, minColIdx);
        }
    }

    return 0;
}
