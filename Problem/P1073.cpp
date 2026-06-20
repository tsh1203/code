#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define FIO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=1e5+5;
struct no{
	int x,y;
};
int n,m,w[N],b[N],ans;
bool vis[N][105];
vector<int>e[N],g[N];
queue<int>q;
queue<no>qq;
void add(int u,int v){
	e[u].push_back(v);
	g[v].push_back(u);
}
void bfs1(){
	q.push(n);
	b[n]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(b[v]) continue;
			b[v]=1;
			q.push(v);
		}
	}
}
void bfs(){
	qq.push({1,0});
	vis[1][0]=1;
	
	while(qq.size()){
		int u=qq.front().x;
		int val=qq.front().y;
		qq.pop();
		if(!val){
			if(!vis[u][w[u]]){
				vis[u][w[u]]=1;
				qq.push({u,w[u]});
			}
		}
		else ans=max(ans,w[u]-val);
		for(int v:e[u]){
			if(!b[v]) continue;
			if(vis[v][val]) continue;
			vis[v][val]=1;
			qq.push({v,val});
		}
	}
}
signed main(){
	FIO
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		add(u,v);
		if(z==2) add(v,u);
	}
	bfs1();
	bfs();
	cout<<ans<<endl;
	return 0;
}
