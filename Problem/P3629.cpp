#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,c,d[100005],fat[100005],fath[100005];
int f[100005],f1[100005],f2[100005];
int head,tail;
int ans;
vector<pair<int,int>>e[100005];
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
		fat[v]=u;
		d[v]=d[u]+w;
		if(d[v]>d[c])c=v;
		dfs2(v,u);
	}
}
void dfs3(int u,int fa)
{ 
	f1[u]=f2[u]=0;
	for(auto i:e[u])
	{ 
		int v=i.first,w=i.second;
		if(v==fa)continue;
		dfs3(v,u);
		int t=f1[v]+w;
		if(t>f1[u])
		{ 
			f2[u]=f1[u];
			f1[u]=t;
		}
		else if(t>f2[u])
		{ 
			f2[u]=t;
		} 
	} 
	f[u]=f1[u]+f2[u];
	ans=max(ans,f[u]);
} 
void dfs4(int u,int fa)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i].first;
		if(v==fa||v!=fat[u])continue;
		fath[v]=u;
		c=v;
		e[u][i].second=-1;
		dfs4(v,u);
	}
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,1});
		e[v].push_back({u,1});
	}
	dfs(1,0);
	d[c]=0;
	dfs2(c,0);
	if(k==1)
	{
		cout<<2*(n-1)-(d[c]-1);
		return 0;
	}
	int an=d[c];
	dfs4(c,0);
	for(int i=1;i<=n;i++)fat[i]=fath[i];
	//for(int i=1;i<=n;i++)cout<<fat[i]<<" ";
	dfs4(c,0);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<e[i].size();j++)
//			cout<<e[i][j].first<<" "<<e[i][j].second<<"\n";
//		cout<<"\n";
//	}
	dfs3(1,0);
	cout<<2*n-an-ans;
	//cout<<endl<<an<<" "<<ans;
	return 0;
}
