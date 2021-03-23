#include <iostream>

using namespace std;

int main()
{
    int a[10010];
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i];
    }
    int i = m;
    while(a[i] == n-m+i){
        i--;
        if(i == 0){
            break;
        }
    }
    if(i == 0){
        cout << -1;
    }
    else{
        a[i] = a[i] + 1;
        for(int j=i+1; j<=m; j++){
            a[j] = a[i] + j -i;
        }
        for(int j=1; j<=m; j++){
            cout << a[j] << " ";
        }
    }
    return 0;
}
