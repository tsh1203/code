#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int head[100005],e[100005],nxt[100005],w[100005],cnt=1;
int f[100005],n,ans;
int f1[100005],f2[100005];
void add(int u,int v,int ww)
{ 
	e[cnt]=v;
	w[cnt]=ww;
	nxt[cnt]=head[u];
	head[u]=cnt++;
} 
void dfs(int u,int fa)
{ 
	f1[u]=f2[u]=0;
	for(int i=head[u];i;i=nxt[i])
	{ 
		int v=e[i];
		if(v==fa)continue;
		dfs(v,u);
		int t=f1[v]+w[i];
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
	if(f[u]>ans)ans=f[u];
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
		add(u,v,w);
		add(v,u,w);
	} 
	dfs(1,0);
	cout<<ans;	
	return 0;
} 
