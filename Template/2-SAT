#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
const int N=4e6+3;
int n,m;
vector<int>e[N],g[N];
int f[N],q[N],cnt,vis[N];
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
	cin>>n>>m;
	while(m--){
		int i,a,j,b;
		cin>>i>>a>>j>>b;
		add(2*i-!a,2*j-b);
		add(2*j-!b,2*i-a);
	}
	scc();
	for(int i=1;i<=n;i++){
		if(f[2*i-1]==f[2*i]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	cout<<"POSSIBLE\n";
	for(int i=1;i<=n;i++){
		if(f[2*i-1]>f[2*i])cout<<1<<" ";
		else cout<<0<<" ";
	}
	return 0;
}
