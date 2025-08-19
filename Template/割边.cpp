#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int dfn[N],low[N],cnt,res;
bool b[N],ans[N];
vector<int>e[N];
vector<pair<int,int>>an;
int fat[N];
void tarjan(int u,int fa){
	fat[u]=fa;
	b[u]=true;
	low[u]=dfn[u]=++cnt;
	for(auto v:e[u]){
		if(!b[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				ans[v]=true;
				res++;
				an.push_back({min(u,v),max(u,v)});
			}
		}else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
		}
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
	sort(an.begin(),an.end());
	for(auto x:an){
		cout<<x.first<<" "<<x.second<<"\n";
	}
	return 0;
}
