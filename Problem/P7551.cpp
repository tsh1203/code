#include<bits/stdc++.h>
#define int long long 
using namespace std;
int head[1000001],cnt,dis[1000001];
int n,x,v,w,m,l,tot,q;
string sx,sy;
struct nod
{
	int nex,to,v;
}a[1000001];
map<string,int>ma;
struct no
{
	int u,d;
};
bool operator<(const no& xx,const no& yy)
{
	return yy.d>xx.d;
}
void add(int x,int y,int l)
{
	cnt++;
	a[cnt].v=l;
	a[cnt].to=y;
	a[cnt].nex=head[x];
	head[x]=cnt;
}
void dij(int x)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18;
	}
	dis[x]=0;
	priority_queue<no>qu;
	qu.push({x,0});
	while(!qu.empty())
	{
		no xx=qu.top();
		qu.pop();
		int uu=xx.u;
		int dd=xx.d;
		if(dd!=dis[uu])continue;
		for(int i=head[uu];i;i=a[i].nex)
		{
			v=a[i].to;
			w=a[i].v;
			if(dis[uu]+w<dis[v])
			{
				dis[v]=dis[uu]+w;
				qu.push({v,dis[v]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>sx>>sy>>l;
		if(!ma[sx])
		{
			tot++;
			ma[sx]=tot;
		}
		if(!ma[sy])
		{
			tot++;
			ma[sy]=tot;
		}
		add(ma[sx],ma[sy],l);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>sx>>sy;
		dij(ma[sx]);
		if(dis[ma[sy]]<1e18)
			cout<<dis[ma[sy]]<<"\n";
		else
			cout<<"Roger"<<"\n";
	}
	return 0;
}
