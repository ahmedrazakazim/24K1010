#include <stdio.h>

int main() {
/* find out year, semester and section */

char roll_number[7], sec;
int Ryear, snum, Ayear;
printf("Using the format of the example (23k-2451)\nEnter your Roll Number: ");
scanf(" %s", &roll_number);

Ayear = ((roll_number[0] - '0') * 10) + (roll_number[1] - '0');
Ryear = 24 - Ayear;
snum = roll_number[4]-'0';
sec = 'A' + (snum - 1);

(Ryear == 0) ? printf("Registration Year: 2024 \nSemester: 1st \nSection: %c",sec) :
(Ryear == 1) ? printf("Registration Year: 2023 \nSemester: 3rd \nSection: %c",sec) :
(Ryear == 2) ? printf("Registration Year: 2022 \nSemester: 5th \nSection: %c",sec) :
(Ryear == 3) ? printf("Registration Year: 2021 \nSemester: 7th \nSection: %c",sec) :
(Ryear == 4) ? printf("Registration Year: 2020 \nExtended year Semester: 1st \nSection: %c",sec) :
printf("Invalid Input");

return 0;
}
