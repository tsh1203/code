#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int k,a,b,ans=1e9;
int dfn[N],low[N],tot;
vector<int>e[N];
int check(int u,int v){
	if((dfn[v]<=dfn[a]&&dfn[v]>dfn[b])||(dfn[v]<=dfn[b]&&dfn[v]>dfn[a]))return 1;
	return 0;
}

void tarjan(int u,int fa){
	dfn[u]=low[u]=++tot;
	for(auto v:e[u]){
		if(!dfn[v]) {
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=a&&u!=b&&check(u,v)){
				ans=min(ans,u);
			}		
		}
		else if(v!=fa)low[u]=min(low[u],dfn[v]);
	}
	return;
}

int main(){
	cin>>n;
	while(1){
		int u,v;
		cin>>u>>v;
		if(u==0&&v==0)break;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cin>>a>>b;
	tarjan(1,0);
	if(ans==1e9)cout<<"No solution";
	else cout<<ans;
	return 0;
} 
