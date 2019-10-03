#include <stdio.h>

int is_prime(int num);

int main(void)
{
  int num, result;
  printf("num:");
  scanf("%d", &num);
  result = is_prime(num);
  if (result == 1)
  {
    printf("%d is prime\n", num);
  }
  else
  {
    printf("%d is not prime\n", num);
  }
  return 0;
}
