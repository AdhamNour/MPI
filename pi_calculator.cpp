#include "mpi.h"
#include "math.h"
#include <iostream>
using namespace std;
long long factorial(const long long &x)
{
    long long result = 1;
    for (long long i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}
long double calculate_pi(const long long int &local_start, const long long int &local_end)
{
    long double result = 0.0;
    for (long long int i = local_start; i <= local_end; i++)
    {
        long double numerator_1_1 = (long double)factorial(i);
        long double numerator_1 = (long double)pow(numerator_1_1, 2);
        long double numerator_2 = (long double)pow(2, i + 1);
        long double denominator = (long double)factorial(2 * i + 1);
        long double numerator = numerator_1 * numerator_2;
        result += numerator/denominator;
    }
    return result;
}
int main(int argc, char *argv[])
{
    int rank, size;
    long long int n = 1000 , local_n, local_start, local_end;
    long double local_pi, total_pi;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    

    local_n = n / size;
    local_start = rank * local_n;
    local_end = (rank + 1) * local_n - 1;
     calculate_pi(local_start,local_end);

    cout<<calculate_pi(local_start,local_end)<<endl;

    MPI_Finalize();
    return 0;
}