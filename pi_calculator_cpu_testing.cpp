#include "mpi.h"
#include "math.h"
#include <stdio.h>
long double factorial(const long double &x)
{
    long double result = 1;
    for (long double i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}

long double calculate_part_of_pi(const long double  &local_start, const long double  &local_end)
{
     double result = 0.0;
    for (long double  i = local_start ;i <= local_end; i++)
    {
         long double numerator_1 = pow(factorial(i), 2);
         long double numerator_2 = pow(2, i + 1);
         long double denominator = factorial(2 * i + 1);
        result+= (numerator_1*numerator_2)/denominator;
    }
    return result;
}


int main(int argc, char *argv[])
{
    int rank, size;
    int  n = 90 , local_n, local_start, local_end;
    long double local_pi, total_pi;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    
    double start = MPI_Wtime();


    local_n = n / size;
    local_start = rank * local_n;
    local_end = (rank + 1) * local_n - 1;
    local_pi=calculate_part_of_pi(local_start,local_end);


    if (rank == 0)
    {
        total_pi = local_pi;
        for (int sender =1; sender < size; sender++)
        {
            MPI_Recv(&local_pi,1,MPI_LONG_DOUBLE,sender,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            total_pi += local_pi;
        }
        printf("The values of pi is %.15Le\n",total_pi);
        printf("The total time for calculation of pi is %.15e\n\n\n\n",MPI_Wtime()-start);

        
    }
    else
    {
        MPI_Send(&local_pi,1,MPI_LONG_DOUBLE,0,0,MPI_COMM_WORLD);
    }
    
    MPI_Finalize();

    return 0;
}