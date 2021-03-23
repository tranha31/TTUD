#include<iostream>
using namespace std;
int n;

int print_int(int *a,int i){
	if (i == -1){
		for (int j=n-1;j>-1;j--){
			cout<<a[j];
		}
		cout<<'\n';
		return 0;
	}
	else{
		a[i] = 0;
		print_int(a,i-1);
		a[i] = 1;
		print_int(a,i-1);
	}
	return 0;
}
const int N=20;
int a[N];
int main(int argc, const char * argv[]){
	cin>>n;
	//for (int i=0;i<n;i++){
	//	a[i] = 0;
	//}
	print_int(a,n-1);
	return 0;
}
