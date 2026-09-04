#include <stdio.h>
#include <omp.h>

int main()
{
    int n, i;
    int positive = 0, negative = 0, zero = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    #pragma omp parallel for reduction(+:positive, negative, zero)
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
            positive++;
        else if (a[i] < 0)
            negative++;
        else
            zero++;
    }

    printf("\nNumber of positive elements = %d", positive);
    printf("\nNumber of negative elements = %d", negative);
    printf("\nNumber of zero elements = %d\n", zero);

    return 0;
}
