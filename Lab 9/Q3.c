#include <stdio.h>

void checkPrime(int count, int numbers[count]);

int main() {
    int i, count;
    
    printf("Number of inputs: ");
    scanf("%d", &count);
    
    int numbers[count]; // Declare the array after getting the count

    for (i = 0; i < count; i++) {
        printf("\nEnter integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    } 

    checkPrime(count, numbers);
    return 0;
}

void checkPrime(int count, int numbers[count]) {
    int i, j;

    for (j = 0; j < count; j++) {
        int divisorCount = 0;

        for (i = 1; i <= numbers[j]; i++) { 
            if (numbers[j] % i == 0) {
                divisorCount++;
            }
        }

        if (divisorCount == 2) {
            printf("\n%d is Prime", numbers[j]);
        } else {
            printf("\n%d is Not Prime", numbers[j]);
        }
    }
}
