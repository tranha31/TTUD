#include <bits/stdc++.h>
using namespace std;

int n, K1, K2;
int x[1001];
int L1 = 0;
int L0 = 0;
const long long A = 1000000007;
unsigned long long dem = 0;

Try(int k){
    if(k > n){
        int tmp = 0;
        for(int i=n; i>=1; i--){
            if(x[i] == 1){
                tmp++;
            }
            else{
                break;
            }
        }
        if(tmp == 0){
            dem++;
            /*for(int i=1; i<=n; i++){
                cout << x[i];
            }
            cout << endl;*/
        }
        else if(K1 <= tmp && tmp <= K2){
            dem++;
            /*for(int i=1; i<=n; i++){
                cout << x[i];
            }
            cout << endl;*/
        }
    }
    else{
        for(int i=0; i<=1; i++){
            //int old_L;
            if(i == 0 && L0 == 0){
                if(k == n-K1+1) continue;
                if(k<=K1 && x[k-1] == 1) continue;
                x[k] = i;
                int old_L1 = L1;
                L1 = 0;
                L0 = 1;
                Try(k+1);
                L1 = old_L1;


            }
            if(i == 1) {
                if(L1 <= K1 || L1+1 <= K2){
                    x[k] = i;
                    int old_L1 = L1;
                    L1 = L1 +1;
                    if(L1 >= K1) L0 = 0;
                    Try(k+1);
                    L1 = old_L1;
                }

            }

        }
    }
}

int main(){
    cin >> n >> K1 >> K2;
    Try(1);
    cout << dem%A;

}
