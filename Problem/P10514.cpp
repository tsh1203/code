#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
const int N=1e6+6,mod=998244353;
int n,m,k;
int f[N],ff[N];
int ksm(int a,int b){
	int r=1;
	a%=mod;
	while(b>0){
		if(b&1)r=r*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return r;
}
int inv(int n){return ksm(n,mod-2);}
void init(int n){
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod;
	ff[n]=inv(f[n]);
	for(int i=n-1;i>=0;i--)ff[i]=ff[i+1]*(i+1)%mod;
}
int C(int n,int r){
	if(r<0||r>n)return 0;
	return f[n]*ff[r]%mod*ff[n-r]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	init(n);
	int d=C(n,k);
	if(!d){cout<<0<<"\n";return 0;}
	int up=1;
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		up=up*C(n-a,k)%mod;
	}
	int ans=up*inv(ksm(d,m))%mod;
	cout<<ans<<"\n";
	return 0;
}
