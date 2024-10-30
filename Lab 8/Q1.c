#include <stdio.h>

int main() {
    int a, b, i, j;
    int isprime;
    
    printf("Enter Starting Number: ");
    scanf("%d", &a);
    printf("Enter Ending Number: ");
    scanf("%d", &b);
    
    for (i = a; i <= b; i++) {
        if (i <= 1)
        continue;  
        isprime = 1;  
        
        for (j = 2; j * j <= i; j++) { 
            if (i % j == 0) { 
                isprime = 0;
                break;
            }
        }
        
        if (isprime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
