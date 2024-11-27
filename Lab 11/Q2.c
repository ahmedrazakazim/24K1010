# include <stdio.h>
# include <string.h>

int main(void) {
	FILE *ptr;
	ptr = fopen("hello.txt","w");
	char name[200];
	char name1[100][50];
	int count[100];
	char temp[]="X";
	
	for ( int  i=0;i<100;i++){
		count[i] =0;
		strcpy(name1[i],temp);
	}
	for (int i=0;i<5;i++){
		printf("Enter line:");
		gets(name);
		fprintf(ptr,"%s\n",&name);
		
	}
	fclose(ptr);
	
int x=0;
int res;

ptr= fopen("hello.txt","r");

while (fscanf(ptr,"%s",name)!= EOF){
	for ( int i=0;i<100;i++){
		res = strcmp(name,name1[i]);
		if(res==0){
			count[i]++;
			break;
		}
		
		}
		if(res!=0){
			strcpy(name1[x],name);
			count[x]=count[x]+1;
			x++;
			
	}
}
	
fclose(ptr);

for ( int  i=0;i<100;i++){
	if ((strcmp(name1[i],temp)))
	printf("%s was repeated %d times\n",name1[i],count[i]);
}
}
