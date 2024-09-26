#include <stdio.h>

int main() {

int x;
x = 5 > 8 ? 10 :
1 != 2 < 5 ? 20 :
30;
printf("Value of X: %d", x);
return 0;
}


In the code above, the value of x is 30. The reason is that, in the ternary operator, the condition before the ? is checked
so in the case of 5 > 8, the output is false, meaning that 10 is skipped and we move onto the expression after the :.
Here, we have the expression 1 != 2 < 5. Due to operator precedence, the expression is evaluated as follows: 
1. 2 < 5 gives us 1
2. then 1 != 1 gives us 0
meaning that this expression is also false, hence the 20 after the ? is skipped and we end up with the value of 30 for x.
