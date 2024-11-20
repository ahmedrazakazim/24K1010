#include <stdio.h>

int linearSearch(int array[], int size, int target, int index)
{
    if (index == size)
        return -1;

    if (array[index] == target)
        return index;

    return linearSearch(array, size, target, index + 1);
}

int main()
{
    int arr[999];
    int numElements, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < numElements; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, numElements, target, 0);

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found.\n", target);

    return 0;
}
