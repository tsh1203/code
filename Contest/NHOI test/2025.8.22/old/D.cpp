#include<bits/stdc++.h>
#define int long long
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
namespace FastIO {
	void read(){}
	template <class T1,class ... T2> inline void read(T1 &x,T2 &... oth){
		bool pd=0;x=0;char ch=getchar();
		while(!isdigit(ch)){pd|=ch=='-';ch=getchar();}
		while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		x=pd?-x:x;
		read(oth...);
	}
	template <class T> void _write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9) _write(x/10);
		putchar(x%10^48);
	}
	void write(){}
	template <class T1,class ... T2>
	inline void write(T1 x,T2 ...oth){_write(x);putchar(' ');write(oth...);}
	inline void endline(){putchar('\n');}
}//Orz lby 
using namespace FastIO;
const int N=2e5+5;
struct edge{
	int to,w;
};
struct no{
	int x,y,z;
};
vector<edge>e[N],ed[N];
vector<no>eds;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
stack<int>s;
int n,m;
int dfn[N],low[N],col[N],cnt,tot;
bool b[N];
int dis[N],vis[N];
void tar(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u);
	b[u]=true;
	for(auto x:e[u]){
		int v=x.to;
		if(!dfn[v]){
			tar(v);
			low[u]=min(low[u],low[v]);
		}
		else if(b[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		tot++;
		while(1){
			int x=s.top();
			s.pop();
			b[x]=0,col[x]=tot;
			if(x==u)break;
		}
	}
}
void dij(int s)
{
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty()){
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
	read(n,m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u,v,w);
		e[u].push_back({v,w});
		eds.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tar(i);
		}
	}
	if(col[1]==col[n]){
		cout<<0;
		return 0;
	}
	for(auto x:eds){
		int u=x.x,v=x.y,w=x.z;
		if(col[u]!=col[v]){
			ed[col[u]].push_back({col[v],w});
		}
	}
	dij(col[1]);
	write(dis[col[n]]);
	return 0;
}
