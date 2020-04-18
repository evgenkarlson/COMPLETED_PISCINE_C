#include <math.h>
#include <iostream>
using namespace std;

void get_divisors(int n);

int main()
{
    while (1)
    {
        int n;

        cin >> n;

        if (n == 0)
            break;

        get_divisors(n);
    }

    return 0;
}

void get_divisors(int n)
{
    int i;

    double sqrt_of_n = sqrt((double)n);

    for (i = 2; i <= sqrt_of_n; i++)
    
        if (n % i == 0)
        {
            cout << i << ", ";

            get_divisors(n / i);

            return;
        }
        else   
            cout << 
}