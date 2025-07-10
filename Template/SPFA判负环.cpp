#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,INF=0x3f3f3f3f;
int t;
int n,m;
int dis[maxn];
int cnt[maxn];
struct no 
{
	int v;
	int w;
};
vector<no>g[maxn];
queue<int>q;
int x,y,z;
bool SPFA(int x)
{
	dis[x] = 0;
	q.push(x);
	while(q.size())
	{
		int u=q.front();q.pop();
		for(auto i:g[u])
		{
			int nv=i.v;
			int nw=i.w;
			if(dis[nv]>dis[u]+nw)
			{
				
				dis[nv]=dis[u]+nw;
				if(++cnt[nv]>=n)return 1;
				q.push(nv);
			}
		}
	}
	return 0;
}
int main()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)g[i].clear();
		
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			if(z>=0)g[x].push_back({y,z}),g[y].push_back({x,z});
			else g[x].push_back({y,z});
		}
		if(SPFA(1))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
