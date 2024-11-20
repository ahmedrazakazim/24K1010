#include <stdio.h>
int rec(int arr [100], int n);
int main() {
    int n, i, arr [100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    rec(arr,n-1);
   
    return 0;
}
int rec(int arr [100], int n) {
    if (n<0) {
        return 0; }
        
  rec(arr, n-1);
    printf("%d \n", arr[n]);
    
} 
