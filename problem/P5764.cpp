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
int dis[100005],vis[100005];
int b[10];
int l[10][10],ans=INT_MAX,re;
bool df[10];
int tem[10],te;
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
	for(int i=0;i<=5;i++)
	{
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[b[i]]=0;
		q.push(make_pair(dis[b[i]],b[i]));
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
		for(int j=0;j<=5;j++)
		{
			l[i][j]=dis[b[j]];
		}
	}
}
void dfs(int w,int x)
{
	df[w]=1;
	if(x>=5)
	{
		ans=min(ans,re);
		df[w]=0;
		return;
	}
	for(int i=1;i<=5;i++)
	{
		if(w!=i&&df[i]==0)
		{
			re+=l[w][i];
			dfs(i,x+1);
			re-=l[w][i];
		}
	}
	df[w]=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	b[0]=1;
	for(int i=1;i<=5;i++)cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		add(a,b,l);
		add(b,a,l);
	}
	dij();
	dfs(0,0);
	cout<<ans;
	return 0;
}
