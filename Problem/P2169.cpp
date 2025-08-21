#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct no{
	int to,w;
};
struct nod{
	int x,y,z;
};
vector<no>e[N],ed[N];
vector<nod>edg;
stack<int>s;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int n,m;
int dfn[N],low[N],color[N],cnt,tot;
bool b[N];
int dis[N],vis[N];
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u);
	b[u]=true;
	for(auto no:e[u]){
		int v=no.to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(b[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		tot++;
		while(true){
			int x=s.top();
			s.pop();
			b[x]=false;
			color[x]=tot;
			if(x==u)break;
		}
	}
}
void dij(int s)
{
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto x:ed[u]){
			int v=x.to,w=x.w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		edg.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	if(color[1]==color[n]){
		cout<<0;
		return 0;
	}
	for(auto to:edg){
		int u,v,w;
		u=to.x,v=to.y,w=to.z;
		if(color[u]!=color[v]){
			ed[color[u]].push_back({color[v],w});
		}
	}
	dij(color[1]);
	cout<<dis[color[n]];
	return 0;
}
