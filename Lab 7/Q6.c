#include <stdio.h>

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[100];
    int counted[100];

    printf("Input:\n");
    
  for (int i = 0; i < size; i++)
    {
        printf("Element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (counted[arr[i]] == 1)
        {
            printf("Number %d occurs more than once.\n", arr[i]);
            return 0;
        }
        counted[arr[i]] = 1;
    }

    printf("No duplicates found.\n");
  
  return 0;
}
