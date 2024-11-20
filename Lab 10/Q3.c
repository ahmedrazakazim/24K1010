#include <stdio.h>

const int MAX_TEMP = 30;

int checkTemperature(int temp)
{
    static int exceedCount = 0;
    if (temp > MAX_TEMP)
    {
        exceedCount++;
    }
    return exceedCount;
}

int main()
{
    int numTemperatures;
    int totalCount = 0;

    printf("Number of temperatures: ");
    scanf("%d", &numTemperatures);

    for (int i = 0; i < numTemperatures; i++)
    {
        int temperature;
        printf("\nEnter temperature %d >", i + 1);
        scanf("%d", &temperature);
        totalCount = checkTemperature(temperature);
    }

    printf("\nCount of temperatures exceeding %d: %d\n", MAX_TEMP, totalCount);

    return 0;
}
