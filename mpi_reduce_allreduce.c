#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]) {
	int rank, x;
	int min, max, sum, prod;
	int amin, amax, asum, aprod;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	x = rank + 1;
	
	// MPI_Reduce
	MPI_Reduce(&x, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
	MPI_Reduce(&x, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	MPI_Reduce(&x, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&x, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
	if(rank == 0) {
		printf("Reduce:\nMin = %d\nMax = %d\nSum = %d\nProd = %d\n", min, max, sum, prod);
	}
	
	// MPI_Allreduce
	MPI_Allreduce(&x, &amin, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
	MPI_Allreduce(&x, &amax, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
	MPI_Allreduce(&x, &asum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	MPI_Allreduce(&x, &aprod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
	printf("Allreduce:\tProcess %d:-\nMin = %d\tMax = %d\tSum = %d\tProd = %d\n", rank, amin, amax, asum, aprod);
	
	MPI_Finalize();
	return 0;
}
