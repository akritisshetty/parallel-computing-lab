#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int total_data[] = {1, 2, 3, 4};
    int local_data;
    int result[4];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Scatter(total_data, 1, MPI_INT, &local_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received %d\n", rank, local_data);

    local_data *= local_data;

    MPI_Gather(&local_data, 1, MPI_INT, result, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result after squaring and gathering: ");
        for (int i = 0; i < size; i++)
            printf("%d ", result[i]);
    }

    MPI_Finalize();
    return 0;
}
