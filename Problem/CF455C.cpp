#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int>e[600005];
int n,m,q;
int d[300005],dis[300005],fa[300005],c;
void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)continue;
		d[v]=d[u]+1;
		if(d[v]>d[c])c=v;
		dfs(v,u);
	}
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		fa[find(u)]=find(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==fa[i])
		{
			c=0;
			d[1]=0;
			dfs(i,0);
			int x=c;
			d[x]=0;c=0;
			dfs(x,0);
			dis[i]=d[c];
		}
	}
	while(q--)
	{
		int op,x,u,v;
		cin>>op;
		if(op==1)
		{
			cin>>x;
			cout<<dis[find(x)]<<endl;
		}
		else
		{
			cin>>u>>v;
			if(find(u)!=find(v))
			{
				int x=find(u),y=find(v);
				dis[y]=max((dis[x]+1)/2+(dis[y]+1)/2+1,max(dis[x],dis[y]));
				fa[x]=y;
			}
		}
	}
	return 0;
}
