#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pai pair<int,int>
using namespace std;
struct edge
{
	int v,w,next;
}e[300005];
int n,m,s,k,t,qq;
int head[300005],cnt;
int dis[2350],vis[2350],sum;
vector<int>d;
priority_queue<pai,vector<pai>,greater<pai>>q;
void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dij()
{
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
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
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cin>>k>>t;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(auto y:d){
			add(x,y,t);
			add(y,x,t);
		}
		d.push_back(x);
	}
	cin>>qq;
	while(qq--){
		int op,x,y,z;
		cin>>op;
		if(op==1){
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		if(op==2){
			cin>>x;
			for(auto y:d){
				add(x,y,t);
				add(y,x,t);
			}
			d.push_back(x);
		}
		if(op==3){
			sum=0;
			for(int i=1;i<=n;i++){
				s=i;
				dij();
				for(int j=1;j<=n;j++)
					if(dis[j]<1e16)
						sum+=dis[j];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
