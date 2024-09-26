#include <stdio.h>

int main() {
    char coftype, manual;
    int dobcup;
    
    printf("'B' for Black\n'W' for White\nPlease select coffee type: ");
    scanf(" %c", &coftype);
    if ((coftype != 'B') && (coftype != 'W')) {   
        printf("Invalid Coffee Type");
return 0;
}
    
    printf("'1' for Double\n'0' for not Double\nPlease select cup size: ");
    scanf("%d", &dobcup);
    
     if (dobcup != 0 && dobcup != 1) {
        printf("Invalid Entry - Double Cup\n");
        return 0;
    }
    
    printf("'Y' for Yes\n'N' for No\nIs your coffee manual? ");
    scanf(" %c", &manual);

    float water = (coftype == 'W') ? 15 : 20;
    float sugar = (coftype == 'W') ? 15 : 20;
    float mix1 = (coftype == 'W') ? 20 : 25;
    float cof = (coftype == 'W') ? 2 : 15;
    float milk = (coftype == 'W') ? 4 : 0;
    float mix2 = (coftype == 'W') ? 20 : 25;

    if (dobcup == 1) {
        water *= 1.5;
        sugar *= 1.5;
        mix1 *= 1.5;
        cof *= 1.5;
        milk *= 1.5;
        mix2 *= 1.5;
    }
    
    printf("Put water: %.2f mins\nSugar: %.2f mins\nMix well: %.2f mins\nAdd Coffee: %.2f mins\nAdd Milk: %.2f mins\nMix well: %.2f mins", water, sugar, mix1, cof, milk, mix2);
    
    return 0;
}
