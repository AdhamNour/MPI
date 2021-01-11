#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	int size,node;
	double start;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&node);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	start = MPI_Wtime();
	if(node == 0)
		printf("Hello from the master, Time = %f\n",MPI_Wtime()-start);
	else
		printf("Hello from the slave #%d, Time = %f\n", node,MPI_Wtime()-start);
	MPI_Finalize();
	return 0;
}
