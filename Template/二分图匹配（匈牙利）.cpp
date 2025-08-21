#include<bits/stdc++.h>
using namespace std;
int n,m,e,ans;
int tim[502],rec[502];
vector<int>ed[502];
bool dfs(int x,int t){
	if(tim[x]==t)
		return false;
	tim[x]=t;
	for(auto y:ed[x]){
		if(rec[y]==0||dfs(rec[y],t)){
			rec[y]=x;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int x,y;
		cin>>x>>y;
		ed[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(dfs(i,i))
			ans++;
	cout<<ans<<endl;
	return 0;
}
