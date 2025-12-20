#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int T;
int n,m,v;
int pre[N];
struct no{
	int c,d;
}a[N];
bool cmp(no a,no b){
	if(a.c!=b.c)return a.c<b.c;
	return a.d<b.d;
}
int qpow(int x,int p){
	int su=1,w=x;
	while(p){
		if(p&1)su=(su*w)%mod;
		w=w*w%mod;
		p>>=1;
	}
	return su;
}
int C(int n,int m){
	int su=1;
	for(int i=1;i<=m;i++)
		su=(((su*(n-m+i))%mod)*pre[i])%mod;
	return su;
}
void solve(){
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++){
		cin>>a[i].c>>a[i].d;
		if(i>1&&a[i].c==a[i-1].c&&a[i].d!=a[i-1].d){
			cout<<0<<endl;
			return;
		}
	}
	sort(a+1,a+m+1,cmp);
	int ans=qpow(v,(a[1].c-1)*2);
	for(int i=1;i<m;i++){
		if(a[i+1].c==a[i].c)continue;
		ans=ans*(qpow(v,(a[i+1].c-a[i].c)*2)-qpow(v,a[i+1].c-a[i].c-1)*(v-1)%mod+mod)%mod;
	}
	ans=ans*qpow(v,(n-a[m].c)*2)%mod;
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=N-3;i++){
		pre[i]=qpow(i,mod-2);
	}
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
3
2 1 2 
1 1
2 2 2
1 1
2 2
2 2 2
1 1 
1 2
*/
