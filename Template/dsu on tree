#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int N=100005;
struct edge{
	int v,nxt;
}e[2*N];
int head[N],cnt;
int n;
int color[N];
int sz[N],s[N];
int pos[N],mx,flag;
int ans[N],sum;
void add(int a,int b){
	e[++cnt]={b,head[a]};
	head[a]=cnt;
}
void dfs1(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		if(e[i].v==fa)
			continue;
		dfs1(e[i].v,u);
		sz[u]+=sz[e[i].v];
		if(sz[e[i].v]>sz[s[u]])
			s[u]=e[i].v;
	}
}
void del(int u,int fa){
	pos[color[u]]--;
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].v!=fa)del(e[i].v,u);
}
void calc(int u,int fa){
	pos[color[u]]++;
	if(pos[color[u]]>mx){
		mx=pos[color[u]];
		sum=color[u];
	}
	else if(pos[color[u]]==mx)
		sum+=color[u];
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].v!=fa&&e[i].v!=flag)
			calc(e[i].v,u);
}
void solve(int u,int fa,bool keep){
	for(int i=head[u];i;i=e[i].nxt) 
		if(e[i].v!=fa&&e[i].v!=s[u])
			solve(e[i].v,u,false);
	if(s[u])
		solve(s[u],u,true),flag=s[u];
	calc(u,fa);
	flag=0;
	ans[u]=sum;
	if(keep==false)
		del(u,fa),sum=mx=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>color[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs1(1,1);
	solve(1,1,1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
