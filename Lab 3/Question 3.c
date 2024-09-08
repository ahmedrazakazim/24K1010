#include <stdio.h>

int main()  { 

int taxRate, tax, salary;
printf("Enter Tax rate: ");
scanf("%d", &taxRate);

printf("\nEnter salary : ");
scanf("%d", &salary);
  
tax = (taxRate/100.0)*salary;
salary = salary - tax;
printf("Your tax amount is %d and your remaining salary is %d" , tax, salary);

return 0; }



