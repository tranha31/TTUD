#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a;
    cin >> b;
    if(a%1000000007+b%1000000007 < 1000000007)
    {
        cout << (a%1000000007+b%1000000007);
    }
    else
    {
        cout << (a%1000000007+b%1000000007 - 1000000007);
    }
    return 0;
}
