#include <iostream>

using namespace std;
int a[10010];
int n;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int j = n - 1;
    while(a[j] > a[j+1]){
        --j;
        if(j == 0){
            break;
        }
    }
    if(j == 0){
        cout << -1;
    }
    else{
        int k = n;
        while(a[j] > a[k]){
            --k;
        }
        swap(a[j], a[k]);
        int l = j+1;
        int r = n;
        while(l < r){
            swap(a[l++], a[r--]);
        }
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
    }
    return 0;
}
