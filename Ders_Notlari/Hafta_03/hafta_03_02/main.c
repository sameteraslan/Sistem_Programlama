#include <stdio.h>
#include <stdlib.h>

int russian(int x, int y);
int main(void)
{
    int x, y, result;
    printf("X:");
    scanf("%d", &x);

    printf("Y:");
    scanf("%d", &y);

    result = russian(x, y);
    printf("Result = %d\n", result);
    return 0;

}