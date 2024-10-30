#include <stdio.h>

int main()
{
    char canvas[105][105] = {};
    int row = 4, col = 0;
    int direction = 1;
    int spaceCount = 1;
    int cycleCount = 0;

    printf("CALCULATING....\n");
    while (cycleCount != 3)
    {
        printf("%d %d %d\n", row, col, spaceCount);
        canvas[row][col] = '*';

        if (direction)
        {
            row--;
            col += spaceCount;
            spaceCount++;
        }
        else
        {
            row++;
            col += spaceCount;
            spaceCount--;
        }
        if (row == 0 && direction == 1)
        {
            direction = 0;
            spaceCount--;
        }
        else if (row == 4 && direction == 0)
        {
            spaceCount = 1;
            direction = 1;
            cycleCount++;
            if (cycleCount != 0)
            {
                canvas[row][col] = '*';
                col += 2;
                if (cycleCount != 3)
                    canvas[row][col] = '*';
            }
        }
    }

    printf("GRID:\n");
    int r = 0;
    while (r <= 4)
    {
        int c = 0;
        while (c < 105)
        {
            if (canvas[r][c] == '*')
            {
                printf("%c", canvas[r][c]);
            }
            else
            {
                printf(" ");
            }
            c++;
        }
        printf("\n");
        r++;
    }

    return 0;
}
