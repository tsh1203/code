#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+4;
int n,m;
vector<int>e[N],g[N];
int f[N],q[N],cnt,vis[N],vis2[N];
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
void dfs3(int u){
	vis[u]=1;
	for(int v:g[u]){
		if(!vis[v])dfs3(v);
	}
}
void dfs4(int u){
	vis2[u]=1;
	for(int v:g[u]){
		if(!vis2[v])dfs4(v);
	}
}
bool check(int x){
	memset(vis,0,sizeof vis);
	memset(vis2,0,sizeof vis2);
	dfs3(2*x-1);dfs4(2*x);
	return (!vis[2*x])&(!vis2[2*x-1]);
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(m--){
		int i,j,a,b;
		char t1,t2;
		cin>>i>>t1>>j>>t2;
		if(t1=='Y')a=1;
		else a=0;
		if(t2=='Y')b=1;
		else b=0;
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
	for(int i=1;i<=n;i++){
		if(check(i))cout<<"?";
		else if(f[2*i-1]>f[2*i])cout<<"Y";
		else cout<<"N";
	}
	return 0;
}
