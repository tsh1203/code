#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
struct no{
	int next,to;
}e[N<<1];
int head[N],cnt;
int n,m,pos[N];
int mx,d;
int sz[N],s[N];
int ans[N],dep[N],so;
void add(int from,int to){
	e[++cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt;
}
void dfs1(int x,int f){
	dep[x]=dep[f]+1;
	sz[x]=1;
	int mx=-1;
	for(int v=head[x];v;v=e[v].next){
		int to=e[v].to;
		if(to==f) continue;
		dfs1(to,x);
		sz[x]+=sz[to];
		if(sz[to]>mx)mx=sz[to],s[x]=to;
	}
}
void add(int x,int f,int val,int now){
	pos[dep[x]]+=val;
	if(pos[dep[x]]>mx||(pos[dep[x]]==mx&&dep[x]-dep[now]<d-dep[now])) mx=pos[dep[x]],d=dep[x];
	for(int v=head[x];v;v=e[v].next){
		int to=e[v].to;
		if(to==f||to==so) continue;
		add(to,x,val,now);
	}
}
void solve(int x,int f,int opt){
	for(int v=head[x];v;v=e[v].next){
		int to=e[v].to;
		if(to==f||to==s[x]) continue;
		solve(to,x,0);
	}
	if(s[x]) solve(s[x],x,1),so=s[x];
	add(x,f,1,x),so=0;
	ans[x]=d;
	if(!opt)add(x,f,-1,x),mx=d=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	solve(1,0,1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]-dep[i]<<endl;
	return 0;
}

