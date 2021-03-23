#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    int b[n+1];
    int c[n+1];
    int vt = 0;
    a[0] = -100000;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = -1;
    }
    int min_s = INT_MAX;
    for(int i=n; i>=1; i--){
        if(a[i] < min_s){
            min_s = a[i];
        }
        c[i] = min_s;
    }
    for(int i=n; i>=1; i--){
        if(a[i] >= a[i-1]){
            vt = i;
        }
        else{
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(i == vt){
            break;
        }
        else if(a[i] <= c[i]){
            continue;
        }
        else{
            for(int j=n; j>=i; j--){
                if(a[j] < a[i]){
                    b[i] = j-i-1;
                    break;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
