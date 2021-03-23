#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 10004;
int n, m;
int a[N], b[N];
int mem[N][N];
int ans = 0;

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    memset(mem, 0, sizeof(mem));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                mem[i][j] = mem[i-1][j-1] + 1;
            }
            else{
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
            ans = max(ans, mem[i][j]);
        }
    }
    cout << ans;
    return 0;
}
