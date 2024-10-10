#include <stdio.h>
int main() {
    char input[100];
    int i;
    int A = 0, E = 0, I = 0, O = 0, U = 0;
        printf("Enter word:\n");
        scanf("%99s", &input[i]);

    for (i = 0; input[i] != '\0' ; i++) {
    	if(input[i] =='A'|| input[i] == 'a'){
    		A++; }
		if(input[i] =='E'|| input[i] == 'e'){
    		E++; }
		if(input[i] =='I'|| input[i] == 'i'){
    		I++; }
		if(input[i] =='O'|| input[i] == 'o'){
    		O++; }
		if(input[i] =='U' || input[i] == 'u'){
    		U++; }
    }
	printf("a = %d e = %d i = %d o = %d u = %d", A, E, I, O, U);
    return 0;
    }
