#include <iostream>

using namespace std;
int n, m, k;
int a[10010];
int dem = 0;

int Try(int l){
    for(int i=a[l-1]+1; i<= n-m+l; i++){
        a[l] = i;
        if(l == m){
            dem++;
            if(dem == k){
                for(int i=1; i<=m; i++){
                    cout << a[i] << " ";
                }
                return 1;
            }
        }
        else{
            Try(l+1);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    a[0] = 0;
    Try(1);
    if(dem < k){
        cout << -1;
    }
    return 0;
}
