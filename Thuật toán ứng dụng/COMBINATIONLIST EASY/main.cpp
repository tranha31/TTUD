#include <iostream>

using namespace std;
int n, m;
int a[10010];

int Try(int l){
    for(int i=a[l-1]+1; i<= n-m+l; i++){
        a[l] = i;
        if(l == m){
            for(int i=1; i<=m; i++){
                cout << a[i] << " ";
            }
            cout << '\n';
        }
        else{
            Try(l+1);
        }
    }
}

int main()
{
    cin >> n >> m;
    a[0] = 0;
    Try(1);
    return 0;
}
