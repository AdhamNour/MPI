#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	int my_rank,comm_sz,n=1024,local_n;
	double a= 0.0, b=3.0, h,local_a,local_b;
	double local_int, total_int;
	int source;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&come_sz);

	h=(b-a)/n;
	local_n =n/come_sz;
	
	local_a = a+ my_rank*local_n*h;
	local_b = local_a + local_n*h;
}
