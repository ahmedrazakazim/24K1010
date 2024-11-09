#include <stdio.h>

void max_min(int arr[], int size);

int main() {
    int arr [50];
    int i,length;
    printf("Enter number of elements: ");
    scanf("%d", &length);
    for (i=0;i<length;i++) {
    printf("Enter Element %d: ", i+1);
    scanf("%d",&arr[i]);
}
max_min(arr, length);

    return 0;
}

void max_min(int arr[], int size) {
        int i; int max=-999999,min=999999;
       // int element1,element2;
        for (i=0;i<size;i++)
    {
        if(arr[i]>max) {
            max=arr[i];
          //  element1=i+1;
        }
        if(arr[i]<min) {
            min=arr[i];
           // element2=i+1;        
        }

    }
    printf("Max Element: %d\nMin Element: %d",max,min);
    
    
}
