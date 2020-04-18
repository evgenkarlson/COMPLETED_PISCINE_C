#include <stdlib.h>
#include <iostream>
using namespace std;

int gcf(int a, int b);
main()
{
    int a = 0, b = 0;

    while (1)
    {
        cin >> a;

        if (a == 0)
            break;

        cin >> b;

        gcf(a, b);
    }
}

int gcf(int a, int b)
{
    if (a % b == 0)
        return b;

    else
    
        return gcf(b, a % b);
}