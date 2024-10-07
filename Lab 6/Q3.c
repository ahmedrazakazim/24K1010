#include <stdio.h>
int main()
{
int n, x=0, c, i;
int a=0,b=1;
printf("Enter a number: "); 
scanf("%d",&n);

for(i=2;i<=n;i++) {
if(i<=n/2 && n%i==0) {
x=1;
break;
}
if(i==2)    
  printf("Series is = %d %d ",a,b);

c=a+b;

if(c<n)
  printf("%d ",c);
  a=b;
  b=c;
}

if(x==0)
printf("\nNumber is prime");

return 0;
}
