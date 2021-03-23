#include <cstdio>
#include <cstring>
using namespace std;
int n[505];
int k,m;
bool slash[505];
long long L,M,R;
bool bs(long long T){
	long long S;
	int num;
	bool flag=true;
	S=0,num=0;
	for(int i=m-1;i>=0;i--){
		S+=n[i];
		if (S>T) {
			num++;
			S=n[i];
			if ((i+1) <= (k-num)) {
				flag=true;
				break;
			}
		}
		if ((i+1) <= (k-num)) {
			flag=true;
			break;
		}
		if (num==k) {
			flag=false;
			break;
		}
	}
	return flag;
}
void pslash(long long T){
	long long S=0;
	int num=0;
	for(int i=m-1;i>=0;i--){
		S+=n[i];
		if (S>T) {
			num++;
			slash[i]=true;
			S=n[i];
			if ((i+1) <= (k-num)) {
				for(int j=0;j<i;j++){
					slash[j]=true;
				}
				break;
			}
		}
		if ((i+1) <= (k-num)) {
			for(int j=0;j<i;j++){
				slash[j]=true;
			}
			break;
		}
	}
}
int main(){
	int ca;
	scanf("%d",&ca);
	for(int i=0;i<ca;i++){
		scanf("%d%d",&m,&k);
		long long sum=0,max=0;
		for(int j=0;j<m;j++){
			scanf("%d",&n[j]);
			sum+=n[j];
			if (max<n[j]) max=n[j];
		}
		L=max,R=sum;
		while(L<R){
			M=(L+R)/2;
			if (bs(M)){
				R=M;
			}else{
				L=M+1;
			}
		}
		memset(slash,0,sizeof(slash));
		pslash(L);
		for(int j=0;j<m;j++){
			if(j==0) printf("%d",n[j]);
			else printf(" %d",n[j]);
			if (slash[j]) printf(" /");
		}
		printf("\n");
	}
}
