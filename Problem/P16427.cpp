#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
int T,n,x,mi[50];
int fun(int n,int x){
	int cnt=0;
	while(n)cnt+=n%x,n/=x;
	return cnt;
}
void solve(){
	cin>>n>>x;
	if(x==1){
		if((n&(n-1))==0)puts("Yes");
		else puts("No");
		return;
	}
	int cnt=fun(n,x);
	for(int i=0;mi[i]<=n;i++){
		int k=mi[i];
		if(k>=cnt&&(k%(x-1)==n%(x-1))){
			puts("Yes");
			return;
		}
	}
	puts("No");
}
signed main(){
	cin>>T;
	mi[0]=1;
	for(int i=1;i<=40;i++)mi[i]=mi[i-1]*2;
	while(T--){
		solve();
	}
	return 0;
}
