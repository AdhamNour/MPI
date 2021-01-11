#include "mpi.h"
#include<stdio.h>
int main (int argc , char* argv[]){
	int rank, buf;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	//Process zero send and Process one recives
	if(rank == 0){
		buf = 123456;
		MPI_Send(&buf,1,MPI_INT,1,0,MPI_COMM_WORLD);
	}
	else if(rank ==1){
		MPI_Recv(&buf,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("recived %d\n",buf);
	}
	MPI_Finalize();
	return 0;
}
