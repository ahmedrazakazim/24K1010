#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main() {
    int n, len;
    char *arr;
    char *id = (char *)malloc(7 * sizeof(char));
    
    if (id == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter total number of characters: ");
    scanf("%d", &n);
    n++;

    arr = (char*)malloc(n * sizeof(char));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter your full name: ");
    scanf(" %[^\n]", arr);
    
    printf("Your name is: %s\n", arr);
    printf("Enter your student ID: ");
    scanf(" %[^\n]", id);
    
    strcat(id, " ");
    len = strlen(id);
    id = (char *)realloc(id, (len + n) * sizeof(char));
    strcat(id, arr);
    
    printf("\n%s\n", id);
    
    free(arr);
    free(id);
    
    return 0;
}
