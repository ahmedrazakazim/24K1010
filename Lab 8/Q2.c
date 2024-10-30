#include <stdio.h>

int main() {
    int num, start;
    printf("Enter the number of pairs: ");
    scanf("%d", &num);
    printf("Enter the starting number: ");
    scanf("%d", &start);

    int arr[2][num][2];
    int cOdd = 0, cEven = 0;

    for (int i = start; cOdd < num || cEven < num; i--) {
        if (i % 2 == 0 && cEven < num) {
            arr[0][cEven][0] = i;
            arr[0][cEven][1] = i - 2;
            cEven++;
        }
        else if (i % 2 != 0 && cOdd < num) {
            arr[1][cOdd][0] = i;
            arr[1][cOdd][1] = i - 2;
            cOdd++;
        }
    }

    printf("Even numbers:\n");
    for (int i = 0; i < num; i++) {
        printf("%d %d\n", arr[0][i][0], arr[0][i][1]);
    }

    printf("Odd numbers:\n");
    for (int i = 0; i < num; i++) {
        printf("%d %d\n", arr[1][i][0], arr[1][i][1]);
    }

    return 0;
}
