#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int next,to,val;
}e[100005];
int uu[100005],h[1003],vv[100005],ww[100005];
int tot,n,m,st,ans[1003],dis[1003];
int vis[1003];
int ma;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void add(int u,int v,int w)
{
	tot++;
	e[tot].next=h[u];
	e[tot].to=v;
	e[tot].val=w;
	h[u]=tot;
}
void dij()
{
	memset(vis,0,sizeof(vis));
	memset(dis,127,sizeof(dis));
	q.push(make_pair(0,st));
	dis[st]=0;
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(!vis[v]&&dis[v]>dis[u]+e[i].val)
			{
				dis[v]=dis[u]+e[i].val;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return;
}
int main()
{
	cin>>n>>m>>st;
	for(int i=1;i<=m;i++)
	{
		cin>>uu[i]>>vv[i]>>ww[i];
		add(uu[i],vv[i],ww[i]);
	}
	dij();
	for(int i=1;i<=n;i++)
	{
		ans[i]=dis[i];
	}
	tot=0;
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		add(vv[i],uu[i],ww[i]);
	}
	dij();
	for(int i=1;i<=n;i++)
	{
		ma=max(dis[i]+ans[i],ma);
	}
	cout<<ma;
	return 0;
}
