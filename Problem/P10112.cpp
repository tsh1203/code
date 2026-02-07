#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define mem memset
#define pii pair<int,int>
using namespace std;
const int N=2e3+3,mod=1e9+7;
int T;
int n,m,a[N];
int f[N]; 
void init(){
	f[0]=1;
	for(int i=1;i<=N-10;i++)f[i]=f[i-1]*i%mod;
}
int ksm(int a,int b){
	int an=1,x=a;
	while(b){
		if(b&1)an=an*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return an;
}
int C(int n,int m){
	if(n<m)return 0;
	return (f[n]*ksm(f[n-m],mod-2)%mod)*ksm(f[m],mod-2)%mod;
}
void solve(){
	int s=0,ans=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i],s+=a[i];
	if(s>n)n++;
	for(int i=1;i<=m;i++){
		ans=ans*C(n,a[i])%mod;
		n-=a[i];
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init();
	cin>>T;
	while(T--)solve();
	return 0;
}
