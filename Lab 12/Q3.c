#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, high = 0, i, new;
    int *arr;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value at element %d: \n", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] > high) {
            high = arr[i];
        }
    }

    printf("largest number entered is %d\n", high);
    printf("enter new resize value for array: \n");
    scanf("%d", &new);

    arr = (int *)realloc(arr, new * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (new > n) {
        printf("Enter %d more elements: \n", new - n);
        for (i = n; i < new; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
            if (arr[i] > high) {
                high = arr[i];
            }
        }
    }

    printf("largest number entered is %d\n", high);
    free(arr);
    return 0;
}
