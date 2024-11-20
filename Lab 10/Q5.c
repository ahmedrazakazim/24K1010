#include <stdio.h>

void bubbleSort(int array[], int size)
{
    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }

    bubbleSort(array, size - 1);
}

int main()
{
    int arr[999];
    int numElements;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numElements; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, numElements);

    printf("Sorted array:\n");
    for (int i = 0; i < numElements; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
