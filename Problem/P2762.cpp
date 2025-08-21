#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=102,M=2e5+5;
const int INF=1e12;
int m,n,s,t;
struct no{
	int to,nxt;
	int cap;
}e[M];
int head[N],tot=1;
int dep[N],cur[N];
void add(int u,int v,int w){
	e[++tot]={v,head[u],w};
	head[u]=tot;
}
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(e[i].cap>0&&!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t]>0;
}
int dfs(int u,int flow){
	if(u==t)return flow;
	int used=0;
	for(int&i=cur[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(e[i].cap>0&&dep[v]==dep[u]+1){
			int f=dfs(v,min(flow-used,e[i].cap));
			if(f>0){
				e[i].cap-=f;
				e[i^1].cap+=f;
				used+=f;
				if(used==flow)break;
			}
		}
	}
	return used;
}
int dinic(){
	int ans=0;
	while(bfs()){
		memcpy(cur,head,sizeof(head));
		ans+=dfs(s,INF);
	}
	return ans;
}
bool b[N];
void cut(int u){
	b[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(e[i].cap>0&&!b[v])
			cut(v);
	}
}
signed main(){
	cin>>m>>n;
	s=0,t=m+n+1;
	int tot=0;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		tot+=x;
		add(s,i,x);
		add(i,s,0);
		
		char tools[10004];
		int l=0,tid;
		memset(tools,0,sizeof(tools));
		getchar();
		cin.getline(tools,10000);
		
		while(sscanf(tools+l,"%lld",&tid)==1){
			add(i,m+tid,INF);
			add(m+tid,i,0);
			int tool=tid;
			if(tool==0){
				l++;
			}
			else{
				while(tool){
					tool/=10;
					l++;
				}
			}
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int u=m+i;
		add(u,t,x);
		add(t,u,0);
	}
	int ans=dinic();
	cut(s);
	for(int i=1;i<=m;i++){
		if(b[i])cout<<i<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		if(b[m+i])cout<<i<<" ";
	}
	cout<<endl<<tot-ans;
	return 0;
}
