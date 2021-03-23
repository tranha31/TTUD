#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, N, C;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        scanf("%d", &C);
        unsigned int arr[N];
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
        }
        unsigned int ans = 1;
        sort(arr, arr+N);
        unsigned int r = 1, l = arr[N-1];
        while(r <= l){
            unsigned int start = arr[0];
            int c = 1;
            unsigned int m = (l+r)/2;
            for(int i=1; i<N; i++){
                if(arr[i] - start >= m){
                    c++;
                    start = arr[i];
                }
            }
            if(c < C){
                l = m-1;
            }
            else{
                ans = m;
                r = m+1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
