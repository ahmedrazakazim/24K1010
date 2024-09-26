#include <stdio.h>

int main() {

long a;
printf("Enter a number: ");
scanf("%ld", &a);
a % 10 == 0 ? printf("Last Digit is Zero!") :
printf ("Last Digit is Non-Zero!");

return 0;
}
