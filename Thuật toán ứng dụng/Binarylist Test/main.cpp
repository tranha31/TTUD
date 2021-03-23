#include <iostream>
#include <string.h>

using namespace std;
int n, k, i;
int dem = 0;
int a[10010];
int old_D = 0;
int D = 0;

int Try(int m){
    if(m > n){
        dem++;
        if(dem == k){
            for(int j=1; j<=n; j++){
                cout << a[j] << " ";
                a[j] = 0;
            }
            return 0;
        }
    }
    else{
        for(int j=0; j<=1; j++){
            if(j == 1){
                a[m] = j;
                old_D = D;
                D = 0;
                //if((n - m) < i){
                  //  dem++;
                    //continue;
                //}
                Try(m+1);
                D = old_D;
            }
            else{
                if(D < i-1){
                    a[m] = j;
                    old_D = D;
                    D++;
                    Try(m+1);
                    D = old_D;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k >> i;
    Try(1);
    if(dem < k){
        cout << -1;
    }
    return 0;
}
