#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,c,d[100005];
vector<pair<int,int>>e[100005];
void dfs(int u,int fa)
{
	for(auto[v,w]:e[u])
	{
		if(v==fa)continue;
		d[v]=d[u]+w;
		if(d[v]>d[c])c=v;
		dfs(v,u);
	}
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0);
	d[c]=0;
	dfs(c,0);
	cout<<d[c];
	return 0;
}
