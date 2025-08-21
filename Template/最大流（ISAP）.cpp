#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
const int M=2e5+5;
const ll INF=1e18;

int n,m,s,t;

struct Edge{
	int to,nxt;
	ll cap;
}e[M];
int head[N],tot=1;
void add(int u,int v,ll w){
	e[++tot]={v,head[u],w};
	head[u]=tot;
}

int dep[N],gap[N],cur[N];
void bfs(){
	memset(dep,-1,sizeof(dep));
	memset(gap,0,sizeof(gap));
	queue<int> q;
	q.push(t);
	dep[t]=0;
	gap[0]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			if(e[i].cap>0&&dep[e[i].to]==-1){
				int v=e[i].to;
				dep[v]=dep[u]+1;
				gap[dep[v]]++;
				q.push(v);
			}
		}
	}
}

ll dfs(int u,ll flow){
	if(u==t)
		return flow;
	ll used=0;
	for(int &i=cur[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(e[i].cap>0&&dep[u]==dep[v]+1){
			ll f=dfs(v,min(flow-used,e[i].cap));
			if(f>0){
				e[i].cap-=f;
				e[i^1].cap+=f;
				used+=f;
				if(used==flow)
					return used;
			}
		}
	}
	gap[dep[u]]--;
	if(gap[dep[u]]==0)
		dep[s]=n+m+2;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}

ll isap(){
	bfs();
	ll ans=0;
	while(dep[s]<n+m+2){
		memcpy(cur,head,sizeof(head));
		ans+=dfs(s,INF);
	}
	return ans;
}

int main(){
	int e; 
	scanf("%d%d%d",&n,&m,&e);
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++){
		add(s,i,1);
		add(i,s,0);
	}
	for(int j=1;j<=m;j++){
		add(n+j,t,1);
		add(t,n+j,0);
	}
	for(int i=1;i<=e;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,n+v,1);
		add(n+v,u,0);
	}
	printf("%lld\n",isap());
	return 0;
}
