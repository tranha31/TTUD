#include <iostream>

using namespace std;
int n, k;
const int M = 1000000007;
long long a[100][100];

int c(int k, int n){
    if(k==0 || k==n){
        return 1;
    }
    else{
        for(int i=0; i<=k; i++){
            for(int j=i; j<=n; j++){
                if(i==0 || i==j){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = a[i-1][j-1] + a[i][j-1];
                    if(a[i][j] > M){
                        a[i][j] %= M;
                    }
                }
            }
        }
    }
    return a[k][n];
}

int main()
{
    cin >> n >> k;
    cout << c(k-1, n+k-1);
    return 0;
}
