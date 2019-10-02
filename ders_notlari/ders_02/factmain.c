#include <stdio.h>

kucuk(a,b);
int main(void)
{
    int a, b, c, d, result;
    printf("a:");
    scanf("%d\n", &a);
    printf("b:");
    scanf("%d\n", &b);

    printf("c:");
    scanf("%d\n", &c);
    printf("d:");
    scanf("%d\n", &d);
    result = kucuk(a, b, c, d);
    printf("Girdiginiz en kucuk sayi = %d\n", result);
    return 0;

}