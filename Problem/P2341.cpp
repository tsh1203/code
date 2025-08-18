#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>e[N];
stack<int>s;
int n,m;
int dfn[N],low[N],color[N],num[N];
int tot,cnt;
bool b[N];
int ctn[N];
void update(int x){
	s.pop();
	color[x]=tot;
	num[tot]++;
	b[x]=false;
}
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	s.push(x);
	b[x]=true;
	for(auto q:e[x]){
		if(!dfn[q]){
			tarjan(q);
			low[x]=min(low[x],low[q]);
		}
		else if(b[q])low[x]=min(low[x],dfn[q]);
	}
	if(low[x]==dfn[x]){
		tot++;
		while(s.top()!=x){
			int t=s.top();
			update(t);
		}
		update(x);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(auto v:e[i]){
			if(color[i]!=color[v]){
				ctn[color[i]]++;
			}
		}
	}
	int iid=-1,cttn=0;
	for(int i=1;i<=tot;i++){
		if(ctn[i]==0){
			cttn++;
			iid=i;
		}
	}
	if(cttn==1){
		cout<<num[iid];
	}else{
		cout<<0;
	}
	return 0;
}
