#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int maxhere = a[0];
    int smax = a[0];
    int u;
    for(int i=1; i<n; i++)
    {
        u = (maxhere + a[i]);
        if(u > a[i])
        {
            maxhere = u;
        }
        else
        {
            maxhere = a[i];
        }
        if(maxhere > smax)
        {
            smax = maxhere;
        }
    }
    cout << smax;
    return 0;
}
