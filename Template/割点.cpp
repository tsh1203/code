#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int dfn[N],low[N],cnt,res;
bool b[N],ans[N];
vector<int>e[N];
void tarjan(int u,int fa){
	b[u]=true;
	low[u]=dfn[u]=++cnt;
	int son=0;
	for(auto v:e[u]){
		if(!b[v]){
			son++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(fa!=u&&low[v]>=dfn[u]&&!ans[u]){
				ans[u]=true;
				res++;
			}
		}else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(fa==u&&son>=2&&!ans[u]){
		ans[u]=true;
		res++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			cnt=0;
			tarjan(i,i);
		}
	cout<<res<<endl;
	for(int i=1;i<=n;i++)
		if(ans[i])cout<<i<<" ";
	return 0;
}
