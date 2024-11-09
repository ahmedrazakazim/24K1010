#include <stdio.h>

void swapIntegers(int numArray[2]);

int main() {
    int numArray[2];
    int i;

    for (i = 0; i < 2; i++) {
        printf("\nEnter integer %d: ", i + 1);
        scanf("%d", &numArray[i]);
    } 

    swapIntegers(numArray);
    return 0;
}

void swapIntegers(int numArray[2]) {
    int temp;

    temp = numArray[0];
    numArray[0] = numArray[1];
    numArray[1] = temp;

    printf("\nSwapped integers:\n");
    for (i = 0; i < 2; i++) {
        printf("Number %d: %d\n", i + 1, numArray[i]);
    }
}
