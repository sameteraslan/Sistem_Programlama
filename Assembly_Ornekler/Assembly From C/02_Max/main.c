#include <stdio.h>

int max(int num1, int num2);

int main(void)
{
  int num1, num2, result;
  printf("num1:");
  scanf("%d", &num1);
  printf("num2:");
  scanf("%d", &num2);
  result = max(num1, num2);
  printf("Max number of (%d, %d) is %d\n", num1, num2, result);

  return 0;
}
