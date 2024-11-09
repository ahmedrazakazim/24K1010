#include <stdio.h>

void Calculator(char inputArray[3]);

int main() {
    int i;
    char inputArray[3];

    for (i = 0; i < 2; i++) {
        printf("\nEnter integer %d: ", i + 1);
        scanf(" %c", &inputArray[i]);
    }

    printf("\nEnter operator: ");
    scanf(" %c", &inputArray[2]);

    Calculator(inputArray);
    return 0;
}

void Calculator(char inputArray[3]) {
    int num1, num2;
    num1 = inputArray[0] - '0';
    num2 = inputArray[1] - '0';

    if (inputArray[2] == '+') {
        printf("Result = %d\n", num1 + num2);
    } else if (inputArray[2] == '-') {
        printf("Result = %d\n", num1 - num2);
    } else if (inputArray[2] == '*') {
        printf("Result = %d\n", num1 * num2);
    } else if (inputArray[2] == '/') {
        if (num2 != 0) {
            printf("Result = %d\n", num1 / num2);
        } else {
            printf("Error: Division by zero\n");
        }
    } else {
        printf("Incorrect operation\n");
    }
}
