#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
vector<int>e[N],ans[N];
int s[N],top;
int cnt,low[N],dfn[N],tot;
int n,m;
void tarjan(int u,int fa){
	int son=0;
	low[u]=dfn[u]=++tot;
	s[++top]=u;
	for(int v:e[u]){
		if(v==fa) continue;
		if(!dfn[v]){
			son++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				cnt++;
				while(s[top+1]!=v) 
					ans[cnt].push_back(s[top--]);
				ans[cnt].push_back(u);
			}
		}
		else 
			low[u]=min(low[u],dfn[v]);
	}
	if(fa==0&&son==0) 
		ans[++cnt].push_back(u);
}


signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			top=0;
			tarjan(i,0);
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		cout<<ans[i].size()<<" ";
		for(int x:ans[i])cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
}
