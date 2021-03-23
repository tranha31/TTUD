#include <iostream>
#include <string.h>

using namespace std;
int n, m;
bool a[100], b[100], c[100];
int dd[100][100];
int dem = 0;

void Try(int i){
    int j;
    for(int j=1; j<=n; j++){
        if(a[j] && b[i+j] && c[i-j+n] && (dd[i][j] == 0)){
            //x[i] = j;
            a[j] = false;
            b[i+j] = false;
            c[i-j+n] = false;
            dd[i][j] = 1;
            if(i == n){
                dem++;
            }
            else{
                Try(i+1);
            }
            a[j] = true;
            b[i+j] = true;
            c[i-j+n] = true;
            dd[i][j] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    int e, f;
    do{
        for(int i=0; i<100; i++){
            a[i] = true;
            b[i] = true;
            c[i] = true;
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dd[i][j] = 0;
            }
        }
        if(m > 0){
            for(int i=1; i<=m; i++){
                cin >> e >> f;
                dd[e][f] = 1;
            }
        }
        Try(1);
        cout << dem << endl;
        dem = 0;
        cin >> n >> m;
    }while(n != 0 || m != 0);
    return 0;
}
