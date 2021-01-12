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
 double calculate_pi()
{
     double result = 0.0;
    for (long long int i = 0 ;i <= 50; i++)
    {
         double numerator_1 = pow(factorial(i), 2);
         double numerator_2 = pow(2, i + 1);
         double denominator = factorial(2 * i + 1);
        result+= (numerator_1*numerator_2)/denominator;
    }
    return result;
}

int main(void)
{
    cout << calculate_pi() << endl;
    return 0;
}