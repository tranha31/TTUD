#include <iostream>

using namespace std;
const int N=1e5+7;
int a[N];
int main()
{
    int n;
    cin>>n;
    int d=0;
    a[0]=N;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=a[i-1]) d++;
    }
    int q;
    cin>>q;
    while (q--){
        int p,c;
        cin>>p>>c;
        if(n == 1){
            cout << 1 << endl;
        }
        else if (a[p]==c){
            cout<<d<<endl;
        }
        else{
            if (p==1){
                if (a[p]==a[p+1]) cout<<++d<<endl;
                else {
                    if (c==a[p+1]) cout<<--d<<endl;
                    else cout << d << endl;
                }
            }
            else if (p==n){
                if (a[p]==a[p-1]) cout<<++d<<endl;
                else{
                    if (c==a[p-1]) cout<<--d<<endl;
                    else cout << d << endl;
                }
            }
            else{
                if (a[p-1]==a[p+1]){
                    if (a[p]==a[p-1]){
                        cout<<d+2<<endl;
                        d=d+2;
                    }
                    else if (c==a[p-1]){
                        cout<<d-2<<endl;
                        d=d-2;
                    }
                    else{
                        cout<<d<<endl;
                    }
                }
                else{
                    if (a[p]==a[p-1]){
                        if (c==a[p+1]){
                            cout<<d<<endl;
                        }
                        else {
                            cout<<++d<<endl;
                        }
                    }
                    else if (a[p]==a[p+1]){
                        if (c==a[p-1]){
                            cout<<d<<endl;
                        }
                        else{
                            cout<<++d<<endl;
                        }
                    }
                    else{
                        if(c==a[p-1] || c==a[p+1]){
                            cout << --d << endl;
                        }
                        else{
                            cout << d << endl;
                        }
                    }
                }
            }
        }
        a[p]=c;
    }
    return 0;
}
