#include <stdio.h>

int main() {

float Principle, interestrate, timeperiod, simpleint;
    
printf("Enter Principle amount between Rs.100 and Rs.1,000,000 : ");
scanf(" %f ", &Principle);

if ((Principle < 100) && (Principle > 1000000)) {
printf("Out of range");
  return 0;
}
  
printf("Enter Interest Rate between 5 and 10 :");
scanf(" %f ", &interestrate);

if ((interestrate < 5) && (interestrate > 10)) {
printf("Out of range");
  return 0;
}
  
printf("Enter Time Period between 1 year and 10 years: ");
scanf(" %f ", &timeperiod);

if ((timeperiod < 1) && (timeperiod > 10))
{
printf("Out of range");
  return 0;
}
  
  simpleint  = (Principle*interestrate*timeperiod)/100;
  printf("The Simple Interest is %f",simpleint);
  ![image](https://github.com/user-attachments/assets/3678e8de-f332-4fb3-87ab-7e34147f476b)

}
