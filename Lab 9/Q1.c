#include <stdio.h>
#include <string.h>

void checkPalindrome(char words[5][20]);

int main() {
    char words[5][20];
    int index;

    for (index = 0; index < 5; index++) {
        printf("\nEnter word %d: ", index + 1);
        scanf("%s", words[index]);
    } 

    checkPalindrome(words);
    return 0;
}

void checkPalindrome(char words[5][20]) {
    int index;
    char reversed[20];

    for (index = 0; index < 5; index++) {
        strcpy(reversed, words[index]);
        strrev(reversed);  

        if (strcmp(reversed, words[index]) == 0) {
            printf("\n%s is a Palindrome", words[index]);
        } else {
            printf("\n%s is not a Palindrome", words[index]);
        }
    }
}
