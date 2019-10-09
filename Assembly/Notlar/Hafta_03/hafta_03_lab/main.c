#include <stdio.h>
#include <stdlib.h>

int sumofarray(int count, int *array);
int main(void)
{
    int count, *arr, i, result;
    printf("Count:");
    scanf("%d", &count);
    
    arr = (int*) malloc (count*sizeof(int));

    for (i = 0; i < count; i++)
    {
        printf("No %d:", i);
        scanf("%d", &arr[i]);
    }

    result = sumofarray(count, arr);
    printf("Toplam = %d\n", result);
    return 0;
}