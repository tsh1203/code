#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define endl "\n"
using namespace std;
const int N=4e6+3;
int n,m,k,w,a[N];
vector<int>e[N],g[N];
int f[N],q[N],cnt,vis[N],tot;
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
//2i-1选 2i不选
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	while(m--){
		int i,j;
		cin>>i>>j;
		add(2*i,2*j-1);
		add(2*j,2*i-1);
	}
	while(k--){
		cin>>w;
		for(int i=1;i<=w;i++)cin>>a[i];
		for(int i=1;i<=w;i++){
			for(int j=i+1;j<=w;j++){
				add(2*a[i]-1,2*a[j]);
				add(2*a[j]-1,2*a[i]);
				tot+=4;
				if(tot>8000000){
					cout<<"TAK";
					return 0;
				}
			}
		}
	}
	scc();
	for(int i=1;i<=n;i++){
		if(f[2*i-1]==f[2*i]){
			cout<<"NIE";
			return 0;
		}
	}
	cout<<"TAK";
	return 0;
}
