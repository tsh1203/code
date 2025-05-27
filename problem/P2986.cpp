#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no
{
	int x,w;
};
int tot,n;
int c[100005];
int ans=LONG_LONG_MAX;
int un[100005],size[100005],f[100005],sum;
vector<no>e[100005];
void dfs(int u,int fa,int d)
{
	size[u]=c[u];
	for(auto y:e[u])
	{
		int v=y.x,w=y.w;
		if(v!=fa)
		{
			dfs(v,u,d+1);
			size[u]+=size[v];
			un[u]+=un[v]+size[v]*w;
		}
	}
}
void dp(int u,int fa)
{
	for(auto y:e[u])
	{
		int v=y.x,w=y.w;
		if(v!=fa)
		{
			f[v]=f[u]-size[v]*w+(tot-size[v])*w;
			dp(v,u);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u,v,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		tot+=c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back({v,w}); 
		e[v].push_back({u,w}); 
	}
	dfs(1,-1,0);
	f[1]=un[1];
	dp(1,0);
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}
