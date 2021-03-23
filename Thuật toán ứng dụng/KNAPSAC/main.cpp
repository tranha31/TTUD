#include <iostream>
#include <algorithm>

using namespace std;
int n, b;
int a[32];
int c[32];

int main()
{
    cin >> n >> b;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> c[i];
    }
    a[0] = 0;
    c[0] = 0;
    int K[n+1][b+1];
    for(int i=0; i<=n; i++){
        for(int j = 0; j<=b; j++){
            if(i==0 || j==0){
                K[i][j] = 0;
            }
            else if(j < a[i]){
                K[i][j] = K[i-1][j];
            }
            else{
                K[i][j] = max(K[i-1][j], c[i]+K[i-1][j-a[i]]);
            }
        }
    }
    cout << K[n][b];
    return 0;
}
