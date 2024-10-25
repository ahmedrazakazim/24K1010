#include <stdio.h>

int main()
{
    int numbers[10];
    int counted[10] = {0};  // Initialize to avoid garbage values

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (counted[i] == 1)
            continue;
        int count = 1;
        for (int j = i + 1; j < 10; j++)
        {
            if (numbers[i] == numbers[j])
            {
                count++;
                counted[j] = 1;
            }
        }
        printf("%d: %d\n", numbers[i], count);
    }

    return 0;
}
