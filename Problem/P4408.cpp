#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,c,d[200005],f[200005];
int first,last;
vector<pair<int,int>>e[200005];
void dfs(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa)continue;
		d[v]=d[u]+w;
		if(d[v]>d[c])c=v;
		dfs(v,u);
	}
}
void dfs2(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa)continue;
		f[v]=f[u]+w;
		if(f[v]>f[c])c=v;
		dfs2(v,u);
	}
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	d[c]=0;
	first=c;
	dfs(first,0);
	int k=d[c];
	last=c;
	dfs2(last,0);
	int ma=0;
	for(int i=1;i<=n;i++)
		if(i!=first&&i!=last)
			ma=max(ma,min(d[i],f[i])+k);
	cout<<ma;
	return 0;
}
