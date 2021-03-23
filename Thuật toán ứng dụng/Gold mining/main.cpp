#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+7;
int n, L1, L2;
int a[N], dp[N];

int main()
{
    cin >> n >> L1 >> L2;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int lower = max(i-L2, 0);
        int upper = max(i-L1, 0);
        for(int j= lower; j<=upper; j++){
           dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += a[i];
    }
    cout << *max_element(dp+1, dp+n+1) << endl;
    return 0;
}
