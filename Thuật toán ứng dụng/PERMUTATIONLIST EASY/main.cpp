#include <iostream>

using namespace std;
int k[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main()
{
    int n;
    cin >> n;
    int m = k[n];
    int a[n+1];
    for(int i=1; i<=n; i++){
        a[i] = i;
        cout << i << " ";
    }
    cout << '\n';
    for(int i=1; i<=m-1; i++){
        int j = n - 1;
        while(a[j] > a[j+1]){
            --j;
            if(j == 0){
                break;
            }
        }
        int l = n;
        while(a[j] > a[l]){
            --l;
        }
        swap(a[j], a[l]);
        int l_ = j+1;
        int r = n;
        while(l_ < r){
            swap(a[l_], a[r]);
            l_++;
            r--;
        }
        for(int e=1; e<=n; e++){
            cout << a[e] << " ";
        }
        cout << '\n';
    }
    return 0;
}
