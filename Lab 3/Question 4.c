#include <stdio.h>

int main() {
int forwardfuel,returnfuel,fuelcost,fuelavg,fconsume,distance;
distance = 1207;
forwardfuel = 118;
returnfuel = 123;

printf("enter car fuel average : ");
scanf("%d",&fuelavg);

if ( fuelavg > 0) {
fuelcost = (distance/fuelavg)*forwardfuel + (distance/fuelavg)*returnfuel;
fconsume = (distance*2)/fuelavg;
printf("\nfuel cost is : %d",fuelcost);
printf("\nfuel consumed is : %d",fconsume); 
} 
else {
printf("negative number try again");
}
return 0;
}

