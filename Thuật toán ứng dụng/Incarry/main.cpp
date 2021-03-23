#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    a[0] = -1;
    int dem = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] > a[i-1]){
            dem++;
        }
    }
    if(dem == n){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
