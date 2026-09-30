/*
Write an MPI program to demonstrate one-to-all communication using MPI_Bcast(). The root process (rank 0) should initialize an integer array containing N elements, and broadcast the array to all other processes. Each process must receive the complete array, calculate its local sum, and display the received elements and calculated sum.
*/

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
	int rank;
	int N = 5;
	int arr[5];
	int sum = 0, i;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		for (i = 0; i < N; i++)
			arr[i] = (i + 1) * 10;
	}

	MPI_Bcast(arr, N, MPI_INT, 0, MPI_COMM_WORLD);

	for (i = 0; i < N; i++)
		sum += arr[i];

	printf("Process %d received: ", rank);

	for (i = 0; i < N; i++)
        	printf("%d ", arr[i]);

	printf("| Sum = %d\n", sum);

	MPI_Finalize();
	return 0;
}
