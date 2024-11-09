#include <stdio.h>
#include <string.h>

void rev(char str[], int size);

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s",str);

    int length = strlen(str);
    rev(str, length);

    return 0;
}

void rev(char str[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
    printf("Reversed string: %s\n", str);
}
