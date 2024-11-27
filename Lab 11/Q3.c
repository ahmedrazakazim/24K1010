# include <stdio.h>
# include <string.h>

int main(void){
	FILE *ptr;
	FILE *ptr2;
	ptr = fopen("check1.txt","w");
	char name[200];
	char check[50];
	char new1[50];
	
	

	for (int i=0;i<5;i++){
		printf("Enter line:");
		gets(name);
		fprintf(ptr,"%s\n",&name);
		
	}
	fclose(ptr);
	printf("Enter the word to replace:");
	scanf("%s",check);
	printf("Enter the new word:");
	scanf("%s",new1);
	
int x=0;
int res;

ptr= fopen("check1.txt","r");
ptr2 = fopen("replace.txt","w");


while (fscanf(ptr,"%s",name)!= EOF){
	
		 res =strcmp(name,check);
		 
		 if (res==0){
		 	fprintf(ptr2,"%s",new1);
		 }
		 else{
		 	fprintf(ptr2,"%s",name);
		 }
		 
		 char c = fgetc(ptr);
    	if (c == '\n') {
        	fprintf(ptr2, "\n");
    	}
	 	else if (c != EOF) {
        	fprintf(ptr2, " ");
    	}
	


}

fclose(ptr);
fclose(ptr2);
}
