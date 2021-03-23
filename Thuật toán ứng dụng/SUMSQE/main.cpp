#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    unsigned int n;
    cin >> n;
    unsigned long long a;
    unsigned long long sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        sum += a;
    }
    cout << sum%1000000007;
    return 0;
}
