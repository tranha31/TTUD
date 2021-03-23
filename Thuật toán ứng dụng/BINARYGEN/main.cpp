#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    int a[100010];
    int n;
    cin >> n;
    int dem = 0;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        a[i] = s[i] - '0';
        if(a[i] == 1){
            dem++;
        }
    }
    if(dem == n){
        cout << -1;
    }
    else{
        int i = n-1;
        while(a[i] != 0){
            i--;
        }
        a[i] = 1;
        for(int j=i+1; j<n; j++){
            a[j] = 0;
        }
        for(int i=0; i<n; i++){
            cout << a[i];
        }
    }
    return 0;
}
