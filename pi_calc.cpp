#include "math.h"
#include <stdio.h>

double factorial(const double &x)
{
    double result = 1;
    for (double i = 1; i <= x; i++)
    {
        result *= i;
    }
    return result;
}
long double calculate_pi()
{
    long double result = 0.0;
    for (double i = 0; i <= 98; i++)
    {
        long double numerator_1 = pow(factorial(i), 2);
        long double numerator_2 = pow(2, i + 1);
        long double denominator = factorial(2 * i + 1);
        result += (numerator_1 * numerator_2) / denominator;
    }
    return result;
}

int main(void)
{
    printf("The valuse of pi is %.25Le\n", calculate_pi());

    return 0;
}