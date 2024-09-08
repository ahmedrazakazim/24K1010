#include<stdio.h>

int main() {
  int  a, b, temp;
  printf("Enter a number: ");
  scanf("%d", &a);
  printf("Enter another number: ");
  scanf("%d", &b);
  temp = b;
  b = a;
  a = temp;

  printf("a=%d\nb=%d", a, b);
}
