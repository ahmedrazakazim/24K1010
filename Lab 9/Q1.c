#include <stdio.h>
#include <string.h>

void checkPalindrome(char words[5][20]);

int main() {
    char words[5][20];
    int i;

    for (i = 0; i < 5; i++) {
        printf("\nEnter word %d: ", i + 1);
        scanf("%s", words[i]);
    } 

    checkPalindrome(words);
    return 0;
}

void checkPalindrome(char words[5][20]) {
    int i;
    char reversed[20];

    for (i = 0; i < 5; i++) {
        strcpy(reversed, words[i]);
        strrev(reversed);  

        if (strcmp(reversed, words[i]) == 0) {
            printf("\n%s is a Palindrome", words[i]);
        } else {
            printf("\n%s is not a Palindrome", words[i]);
        }
    }
}
