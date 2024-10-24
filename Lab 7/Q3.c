#include <stdio.h>

int main() {
    char arr[50];
    char *ptr = arr;  
    int count = 0;

    printf("Enter a word: ");
    scanf("%49s", arr); 
    while (*ptr != '\0') {
        count++;
        ptr++; 
    }

    printf("Your word has the length of %d letters\n", count);
    
    return 0;
}
