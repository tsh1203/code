#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int next,to,dis;
}e[1000006];
struct no
{
	int dis,pos;
	bool operator <(const no&x)const
	{
		return x.dis<dis;
	}
};
int n,m,p,tot,ans=INT_MAX,sum;
int f[500005],dis[500005],head[500005],id[500005];
priority_queue<no>q;
void add(int x,int y,int w)
{
	tot++;
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
	e[tot].dis=w;
}
void dij(int w)
{
	q.push((no){0,w});
	while(!q.empty())
	{
		no k=q.top();
		q.pop();
		int x=k.pos;
		if(f[x])continue;
		f[x]=1;
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].dis)
			{
				dis[y]=dis[x]+e[i].dis;
				if(!f[y])q.push({dis[y],y});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>p>>m;
	for(int i=1;i<=n;i++)cin>>id[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);add(y,x,z); 
	}
	for(int i=1;i<=p;i++)
	{
		memset(f,0,sizeof(f));
		memset(dis,127,sizeof(dis));
		dis[i]=0;
		dij(i);
		sum=0;
		for(int j=1;j<=n;j++)sum+=dis[id[j]];
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
