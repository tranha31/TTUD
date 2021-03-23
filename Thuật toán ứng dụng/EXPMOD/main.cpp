#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long a, b, result;
    cin >> a;
    cin >> b;
    result = 1;
    a = a % 1000000007;
    b = b % 1000000006;
    while(b > 0)
    {
        if(b%2 > 0)
        {
            result = result * a % 1000000007;
        }
        a = a * a % 1000000007;
        b = b/2;
    }
    cout << result;
    return 0;
}
