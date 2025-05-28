#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,r,dn,dfn[500005],mi[19][500005];
vector<int>e[500005];
int get(int x,int y)
{
	if(dfn[x]<dfn[y])return x;
	return y;
}
void dfs(int u,int f)
{
	mi[0][dfn[u]=++dn]=f;
	for(int v:e[u])if(v!=f)dfs(v,u); 
}
int lca(int u, int v)
{
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))swap(u,v);
	int d=__lg(v-u++);
	return get(mi[d][u],mi[d][v-(1<<d)+1]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>r;
	for(int i=2;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(r,0);
	for(int i=1;i<=__lg(n);i++)
	{
		for(int j=1;j+(1 << i)-1<= n;j++)
		{
			mi[i][j]=get(mi[i-1][j],mi[i-1][j+(1<<i-1)]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<endl;
	}
	return 0;
}
