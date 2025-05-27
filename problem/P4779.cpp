#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pai pair<int,int>
using namespace std;
struct edge
{
	int v,w,next;
}e[200005];
int n,m,s,t;
int x[102],y[102];
int head[200005],idx;
int dis[100005],vis[100005],sum,ans[100005];
priority_queue<pai,vector<pai>,greater<pai>>q;
void add(int u,int v,int w)
{
	e[++idx].v=v;
	e[idx].w=w;
	e[idx].next=head[u];
	head[u]=idx;
}
void dij()
{
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	q.push(make_pair(dis[1],1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		add(a,b,l);
	}
	dij();
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	return 0;
}
