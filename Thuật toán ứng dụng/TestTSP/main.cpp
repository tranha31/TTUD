#include<iostream>
#include<conio.h>

using namespace std;

#define MAX 50
#define TRUE 1
#define FALSE  0
int A[MAX][MAX];//ma trận liền kề.
int C[MAX], B[MAX];
int n;//số đỉnh của đồ thị.
int d;//đếm số lượng chu trình hamilton.
int a,b,c,m;
int minx = INT_MAX;

void Init(){
    cin >> n >> m;
    //nhập ma trận kề
    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        A[a][b] = c;
    }
    for(int i=1; i<=n; i++){
        C[i] = 0;
    }
}

void Result(){
    cout<<"Chu trinh Hamilton: ";
    for(int i=n; i>=0; i--)
        cout<<B[i]<<" ";
    d++;
    cout<<endl;
}

void Hamilton(int *B, int *C, int i){
    int j, k;
    int f = 0;
    for(j=1; j<=n; j++){
        if(A[B[i-1]][j]!=0 && C[j]==0){
            B[i]=j; C[j]=1;
            if(i<n) Hamilton(B, C, i+1);
            else
                if(B[i]==B[0]){
                    for(int j=n; j>0; j--){
                        f += A[B[j]][B[j-1]];
                    }
                    if(f < minx){
                        minx = f;
                    }
                }
            C[j]=0;
        }
    }
}

int main(){
    B[0]=1;
    int i=1;
    d=0;
    Init();
    Hamilton(B,C,i);
    cout << minx;
    //if(d==0)
        //cout<<"Khong co chu trinh Hamilton";
    return 0;
}
