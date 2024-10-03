//The do-while loop would be best for user input

#include <stdio.h>

int main() {
int a;
int x=0;
do {
    
printf("Enter a number: ");
scanf("%d", &a);
if (a == 0)
break;
    printf("%d + %d = %d\n",a,x,x+a); 
    x=x+a;
}
while (a!=0);

    return 0;
}
