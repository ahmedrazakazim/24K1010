#include <stdio.h>
int main() {
    int arr[6]; 
    int i, temp;

    for (i = 0; i < 6; i++) {
    	printf("Enter a number:\n");
        scanf("%d", &arr[i]);
    }
    temp = arr[5];

    for (i = 5; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp; 
    printf("After right shift:\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
