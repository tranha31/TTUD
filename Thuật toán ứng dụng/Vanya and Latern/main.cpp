#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>

#define N 1005
using namespace std;

int main (int argc, char * argv[])
{
    int n, l, lantern[N];
    int i, j, tmp;
    float d, maximum_distance, left_border, right_border;

    scanf("%d%d", &n, &l);

    for(i=0; i<n; i++)
        scanf("%d", &lantern[i]);
    for(i=0; i<n-1; i++)
        for(j=i; j<n; j++)
            if(lantern[j]<lantern[i]){
                tmp=lantern[i];
                lantern[i]=lantern[j];
                lantern[j]=tmp;
            }
    //sort(lantern, lantern+n);
    maximum_distance = 0;
    for(i=0; i<n-1; i++) {
        if( (lantern[i+1]-lantern[i]) > maximum_distance )
            maximum_distance = lantern[i+1]-lantern[i];
    }
    d = maximum_distance/2;
    left_border = lantern[0];
    right_border = l-lantern[n-1];
    d = max(d, max(left_border, right_border));
    printf("%.10f\n", d);

    return 0;
}
