#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+5;
int n,m,c,d[N];
int cnt[N],fa[N];
vector<int>e[N];
void dfs(int u,int fa){
	for(auto v:e[u]){
		if(v==fa||v==0)continue;
		d[v]=d[u]+cnt[v]-1;
		if(d[v]>d[c])c=v;
		dfs(v,u);
	}
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		cnt[u]++,cnt[v]++;
	}
	dfs(1,0);
	d[c]=cnt[c]+1;
	dfs(c,0);
	if(m==1)cout<<2;
	else cout<<d[c];
	return 0;
}
