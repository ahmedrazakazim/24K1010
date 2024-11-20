#include <stdio.h>

void displayArr(int arr[], int n, int start)
{
    if (start >= n)
        return;

    printf("%d ", arr[start]);
    displayArr(arr, n, start + 1);
}

int main()
{
    int num[] = {0, 1, 2, 3, 4, 5};

    int size = sizeof(num) / sizeof(num[0]);

    displayArr(num, size, 0);

    return 0;
}
