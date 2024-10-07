#include<stdio.h>
int main(){
int i=1;
do {
 if ((i!=1)&&(i!=6)) {
	printf("*  *  *  *  *\n");
 }
 else 
  printf("*           *\n");
	i++;}
while(i<=6);
return 0;
}
