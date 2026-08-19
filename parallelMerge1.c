#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500000

void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, i, j, k;
    int *L = malloc(n1 * sizeof(int)), *R = malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        L[i] = a[l + i];

    for(j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = j = 0;
    k = l;

    while(i < n1 && j < n2)
        a[k++] = L[i] < R[j] ? L[i++] : R[j++];

    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

// d: depth of parallelism
void sort(int *a, int l, int r, int d) {
    if(l >= r)
        return;

    int m = (l + r) / 2;

    if(d > 0) {
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                printf("Thread %d working on left [%d..%d]\n",
                       omp_get_thread_num(), l, m);
                sort(a, l, m, d - 1);
            }

            #pragma omp section
            {
                printf("Thread %d working on right [%d..%d]\n",
                       omp_get_thread_num(), m + 1, r);
                sort(a, m + 1, r, d - 1);
            }
        }
    } else {
        sort(a, l, m, 0);
        sort(a, m + 1, r, 0);
    }

    merge(a, l, m, r);
}

int main(void) {
    omp_set_nested(1);

    int *a = malloc(N * sizeof(int));
    int *b = malloc(N * sizeof(int));

    // fill array with random numbers
    for(int i = 0; i < N; i++)
        a[i] = b[i] = rand();

    double t = omp_get_wtime();

    sort(a, 0, N - 1, 0); // depth = 0 -> sequential
    printf("\nSeq: %f seconds\n", omp_get_wtime() - t);

    // Parallel version
    t = omp_get_wtime();

    sort(b, 0, N - 1, 2); // depth = 2 -> parallel up to 2 levels

    printf("Par: %f seconds\n", omp_get_wtime() - t);

    free(a);
    free(b);

    return 0;
}
