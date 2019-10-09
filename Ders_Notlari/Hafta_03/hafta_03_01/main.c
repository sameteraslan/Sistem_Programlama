#include <stdio.h>
#include <stdlib.h>

int smallest(int count, int *array);
int main(void)
{
    int count, *arr, i, result;
    printf("Count:");
    scanf("%d", &count);
    
    arr = (int*) malloc (count*sizeof(int));

    for (i = 0; i < count; i++)
    {
        printf("No %d:\n", i);
        scanf("%d", &arr[i]);
    }

    result = smallest(count, arr);
    printf("Girdiginiz en kucuk sayi = %d\n", result);
    return 0;

}