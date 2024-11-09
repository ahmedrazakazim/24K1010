#include <stdio.h>

void sort(char arr[][100], int n) {
    char temp[100];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][0] > arr[j][0]) {
                for (int k = 0; arr[i][k] != '\0'; k++) {
                    temp[k] = arr[i][k];
                }
                temp[strlen(arr[i])] = '\0';

                for (int k = 0; arr[j][k] != '\0'; k++) {
                    arr[i][k] = arr[j][k];
                }
                arr[i][strlen(arr[j])] = '\0';

                for (int k = 0; temp[k] != '\0'; k++) {
                    arr[j][k] = temp[k];
                }
                arr[j][strlen(temp)] = '\0';
            }
        }
    }
}

int main() {
    char strings[100][100];
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    printf("\nOriginal array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    sort(strings, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
