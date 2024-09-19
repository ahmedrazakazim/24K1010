#include <stdio.h>

int main() {
  float Cf;
  float fg;
  float Cal;
  float percentage;
  printf("Enter number of fat grams:");
  scanf("%f", &fg);
  printf("Enter Calories: ");
  scanf("%f", &Cal);
  if ((fg > 0) && (Cal >0) ) {
      Cf = fg *9;
      if(Cf <= Cal) {
      percentage = (Cf*100)/Cal;
      printf("%.2f are the calories from fat in your food", percentage);}
      else {
          printf("Either fat grams or calories were incorrectly entered.");
      }
  }
  else 
      printf("Either fat grams or calories were incorrectly entered.");
      return 0;
}
