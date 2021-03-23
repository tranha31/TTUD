#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    int a[n+1];
    int max_l[n+1];
    int max_r[n+1];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    max_l[0] = a[0];
    for(int i=1; i<=n-1; i++){
        max_l[i] = max(max_l[i-1], a[i]);
    }
    max_r[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        max_r[i] = max(max_r[i+1], a[i]);
    }
    int sum = -1;
    for(int i=1; i<=n-2; i++){
        int l = max_l[i-1] - a[i];
        int r = max_r[i+1] - a[i];
        if(l >=b && r>=b){
            sum = max(sum, l+r);
        }
    }
    cout << sum;
    return 0;
}
