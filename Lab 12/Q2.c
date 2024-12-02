#include <stdio.h>

void swaped(int *aPtr, int *bPtr, int *cPtr) {
    int temp = *bPtr;
    *bPtr = *aPtr;
    *aPtr = *cPtr;
    *cPtr = temp;
}

int main() {
    int a, b, c;

    printf("Enter value for first variable: ");
    scanf("%d", &a);

    printf("Enter value for second variable: ");
    scanf("%d", &b);

    printf("Enter value for third variable: ");
    scanf("%d", &c);

    swaped(&a, &b, &c);

    printf("After swapping:\n");
    printf("First variable value: %d\n", a);
    printf("Second variable value: %d\n", b);
    printf("Third variable value: %d\n", c);

    return 0;
}
