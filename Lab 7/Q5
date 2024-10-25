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
        for (int next = i + 1; next < 10; next++)
        {
            if (numbers[i] == numbers[next])
            {
                count++;
                counted[next] = 1;
            }
        }
        printf("%d: %d\n", numbers[i], count);
    }

    return 0;
}
