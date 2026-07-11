#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
const int N=6e4+3;
int n,m,a[N],s;
vector<int>e[N],g[N];
int f[N],q[N],cnt,vis[N];
void init(){
	for(int i=1;i<N;i++)e[i].clear(),g[i].clear();
	memset(f,0,sizeof f);
	memset(q,0,sizeof q);
	memset(vis,0,sizeof vis);
	cnt=s=0;
}
void add(int a,int b){
	e[a].push_back(b);
	g[b].push_back(a);
}
void dfs(int u){
	vis[u]=1;
	for(int v:e[u]){
		if(!vis[v])dfs(v);
	}
	q[++cnt]=u;
}
void dfs2(int u){
	f[u]=cnt;
	for(int v:g[u]){
		if(!f[v])dfs2(v);
	}
}
void scc(){
	for(int i=1;i<=2*n;i++){
		if(!vis[i])dfs(i);
	}
	cnt=0;
	for(int i=2*n;i>0;i--){
		if(!f[q[i]]){
			cnt++;
			dfs2(q[i]);
		}
	}
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		init();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s+=a[i];
		}
		for(int i=1;i<=n;i++){
			a[i]=((a[i]*n)<s);
		}
		while(m--){
			int i,j;
			cin>>i>>j;
			if(a[i]==a[j]){
				add(2*i,2*j-1);
				add(2*j,2*i-1);
				add(2*j-1,2*i);
				add(2*i-1,2*j);
			}
			else{
				add(2*i,2*j-1);
				add(2*j,2*i-1);
			}
		}
		scc();
		int fl=1ll;
		
		for(int i=1;i<=n;i++){
			if(f[2*i-1]==f[2*i]){
				cout<<"No solution.\n";
				fl=0ll;
				break;
			}
		}
		if(fl){
			for(int i=1;i<=n;i++){
				if(f[2*i]>=f[2*i-1]){
					cout<<"C\n";
				}
				else{
					if(a[i]==1)cout<<"B\n";
					else cout<<"A\n";
				}
			}
		}
		
	}
	return 0;
}
