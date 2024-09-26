#include<stdio.h>
int main() {
float water = 15, sugar = 15, mix1 = 20, cof = 2, milk = 4, mix2 = 20;
float bwater = 20, bsugar = 20, bmix1 = 25, bcof = 15, bmilk = 0, bmix2 = 25;
char coftype, manual;
int dobcup;
    
printf("'B' for Black \n'W' for White \nPlease select coffee type: ");
scanf("%c", &coftype);
printf("'1' for Double \n'0' for not Double \nPlease select cup size: ");
scanf("%d", &dobcup);
printf("'Y' for Yes \n'N' for No \nIs your coffee manual? ");
scanf(" %c", &manual);
switch(dobcup){
	case 0:
	if(coftype == 'W'){
	 	printf("Put water: %.2f mins \nSugar: %.2f mins \nMix well: %.2f mins \nAdd Coffee: %.2f mins \nAdd Milk: %.2f mins \nMix well: %.2f mins", water,sugar,mix1,cof,milk,mix2);
	 	}
	else if(coftype == 'B'){
		printf("Put water: %.2f mins \nSugar: %.2f mins \nMix well: %.2f mins \nAdd Coffee: %.2f mins \nAdd Milk: %.2f mins \nMix well: %.2f mins", bwater,bsugar,bmix1,bcof,bmilk,bmix2);
		}
	else if ((coftype != 'B') && (coftype != 'W')){ 
	printf("Invalid Entry- Coffee Type");
	}
	break;
	case 1:
	if(coftype == 'W'){
	 	printf("Put water: %.2f mins \nSugar: %.2f mins \nMix well: %.2f mins \nAdd Coffee: %.2f mins \nAdd Milk: %.2f mins \nMix well: %.2f mins", (water*1.5),(sugar*1.5),(mix1*1.5),(cof*1.5),(milk*1.5),(mix2*1.5));
	 	}
	else if(coftype == 'B'){
		printf("Put water: %.2f mins \nSugar: %.2f mins \nMix well: %.2f mins \nAdd Coffee: %.2f mins \nAdd Milk: %.2f mins \nMix well: %.2f mins", (bwater*1.5),(bsugar*1.5),(bmix1*1.5),(bcof*1.5),(bmilk*1.5),(bmix2*1.5));
		}
	else if ((coftype != 'B') && (coftype != 'W')){ 
	printf("Invalid Entry- Coffee Type");
	}
	break;
	default:
        printf("Invalid Entry- Double Cup");
	}  
return 0;
}
