#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int x, dem = 0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            x = k - a[i] - a[j];
            int r = j+1, l = n-1;
            int sum = 0;
            while(r <= l){
                int m = (r+l)/2;
                if(a[m] < x){
                    r = m+1;
                }
                else if(a[m] > x){
                    l = m-1;
                }
                else{
                    for(int q=m; q>=r; q--){
                        if(a[q] == x){
                            sum++;
                        }
                        else{
                            break;
                        }
                    }
                    for(int q=m; q<=l; q++){
                        if(a[q] == x){
                            sum++;
                        }
                        else{
                            break;
                        }
                    }
                    sum--;
                    break;
                }
            }
            dem += sum;
        }
    }
    printf("%d", dem);
    return 0;
}
