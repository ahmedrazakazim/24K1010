#include <stdio.h>

int main() {

float gpa;
printf("Enter your GPA: ");
scanf("%f", &gpa);

((gpa < 0.00) || (gpa > 4.00)) ? printf("Invalid Input!") :
((gpa >= 0.00) && (gpa <= 0.99)) ? printf("Failed Semester - registration suspended.") :
((gpa >= 1.00) && (gpa <= 1.99)) ? printf("On probation for next semester.") :
((gpa >= 2.00) && (gpa <= 2.99)) ? printf("No Message."):
((gpa >= 3.00) && (gpa <= 3.49)) ? printf("Dean's list for semester.") :
((gpa >= 3.50) && (gpa <= 4.00)) ? printf("Highest honors for semester.") : printf("Invalid Input!"); 

return 0;
}
