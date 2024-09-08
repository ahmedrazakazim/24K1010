#include <stdio.h>

int main() {
  
  float x1 = 5;
  float y1 = 4;
  float x2 = 3;
  float y2 = 2;
  float slope = (y2 - y1) / (x2 - x1);

  printf("Slope: %.3f", slope);
  return 0;
}
