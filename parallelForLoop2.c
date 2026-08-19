// Parallelly printing n iterations using threads (OpenMP)

#include <stdio.h>
#include <omp.h>

int main(void) {
	int n;
	
	printf("Enter number of iterations: ");
	scanf("%d", &n);
	
	omp_set_num_threads(4);
	
	#pragma omp parallel for schedule(static, 2)
	for(int i = 0; i < n; i++) {
		int tid = omp_get_thread_num();
		printf("Thread %d is executing iteration %d\n", tid, i);
	}
	
	return 0;
}
