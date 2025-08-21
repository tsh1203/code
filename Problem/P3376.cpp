#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int n,m,s,t;
int ans,dis[N];
int tot=1,b[N],pre[N];
struct node{
	int to,nxt;
	int val;
}e[520010];
int head[N],fl[1002][1002];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].val=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}

int bfs(){
	memset(b,0,sizeof b);
	queue<int>q;
	b[s]=1;
	dis[s]=INT_MAX;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(e[i].val==0||b[v]==1)continue;
			dis[v]=min(dis[x],e[i].val);
			pre[v]=i; 
			q.push(v);
			b[v]=1;
			if(v==t)return 1;
		}
	}
	return 0;
}

void upd(){
	int x=t;
	while(x!=s){
		int v=pre[x];
		e[v].val-=dis[t];
		e[v^1].val+=dis[t];
		x=e[v^1].to;
	}
	ans+=dis[t];
}

signed main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(fl[u][v]==0){
			add(u,v,w);
			add(v,u,0);
			fl[u][v]=tot;
		}
		else{
			e[fl[u][v]-1].val+=w;
		}
	}
	while(bfs()!=0){
		upd();
	}
	cout<<ans;
	return 0;
}
