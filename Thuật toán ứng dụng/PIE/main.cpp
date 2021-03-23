#include <iostream>
#include <algorithm>

using namespace std;
const float PI = 3.141592;
const float EPS = 0.0000001;

int main()
{
    int t, N, F;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        scanf("%d", &F);
        F++;
        int arr[N];
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
            arr[i] *= arr[i];
        }
        //arr[0] = 0;
        sort(arr, arr+N);
        float r=0.0, l=arr[N-1];
        float ans = 0;
        while(r + EPS < l){
            float m = (l+r)/2;
            int dem = 0;
            for(int i=0; i<N; i++){
                dem += (int)(arr[i]/m);
            }
            if(dem < F){
                l = m;
            }
            else{
                r = m;
            }
        }
        ans = r;
        printf("%.6f\n", PI*ans);
    }
    return 0;
}
