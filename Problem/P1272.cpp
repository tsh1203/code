#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int n,p;
vector<int>son[N];
int f[N][N];
void dfs(int u){
	for(int i=1;i<=n;i++)f[u][i]=1e18;
	f[u][1]=son[u].size();
	for(auto v:son[u]){
		dfs(v);
		static int g[N];
		for(int i=1;i<=n;i++)g[i]=1e18;
		for(int i=1;i<=n;i++){
			if(f[u][i]>=1e18)continue;
			g[i]=min(g[i],f[u][i]);
			for(int j=1;j<=n;j++){
				if(f[v][j]>=1e18)continue;
				g[i+j]=min(g[i+j],f[u][i]+f[v][j]-1);
			}
		}
		for(int i=1;i<=n;i++)f[u][i]=g[i];
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>p;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		son[u].push_back(v);
	}
	dfs(1);
	int ans=1e18;
	for(int i=1;i<=n;i++)ans=min(ans,f[i][p]+(i!=1));
	cout<<ans;
	return 0;
}
