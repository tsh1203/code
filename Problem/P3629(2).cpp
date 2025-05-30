#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;

int n,k;
struct WL{
	int v,w;
};
vector<WL> e[N];

int c,d[N];
void dfs(int u,int fa){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		if(v==fa) continue;
		d[v]=d[u]+e[u][i].w;
		if(d[v]>d[c]) c=v;
		dfs(v,u);
	}
}
int f[N];
void dfss(int u,int fa){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		if(v==fa) continue;
		f[v]=u;
		d[v]=d[u]+e[u][i].w;
		if(d[v]>d[c]) c=v;
		dfss(v,u);
	}
}
int ff[N];
void dfsss(int u,int fa){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		if(v==fa||v!=f[u]) continue;
		ff[v]=u;
		c=v;
		e[u][i].w=-1;
		dfsss(v,u);
	}
}

int dp[N],d1[N],d2[N];
void dfs2(int u,int fa){
	d1[u]=d2[u]=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v;
		if(v==fa) continue;
		dfs2(v,u);
		int t=d1[v]+e[u][i].w;
		if(t>d1[u]) d2[u]=d1[u],d1[u]=t;
		else if(t>d2[u]) d2[u]=t;
	}
	dp[u]=d1[u]+d2[u];
}

int ans1,ans2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a].push_back({b,1});
		e[b].push_back({a,1});
	}
	
	dfs(1,0);
	d[c]=0;
	dfss(c,0);
	ans1=d[c];
	
	if(k==1){
		cout<<2*(n-1)-(ans1-1);
		return 0;
	}
	
//	cout<<"c: "<<c<<"\n";
	dfsss(c,0);
	for(int i=1;i<=n;i++) f[i]=ff[i];
//	cout<<"-\n";
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//	cout<<"\n-\n";
	dfsss(c,0);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<e[i].size();j++)
			cout<<e[i][j].v<<" "<<e[i][j].w<<"\n";
		cout<<"\n";
	}
	
	dfs2(1,0);
	for(int i=1;i<=n;i++) 
		ans2=max(ans2,dp[i]);
	
	cout<<n*2-ans1-ans2;
	return 0;
}
