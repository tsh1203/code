#include<bits/stdc++.h>
using namespace std;
const int N=102,M=502;
int n,m;
int w[N],v[N];
int d[N];
vector<int>adj[N],tadj[N];
int nw[N],nv[N];
int scc[N],cnt;
int low[N],dfn[N],ts;
stack<int>s;
bool ins[N];
int dp[N][M];
bool b[N];
void tarjan(int u){
	dfn[u]=low[u]=++ts;
	s.push(u);
	ins[u]=true;
	for(int vv:adj[u]){
		if(!dfn[vv]){
			tarjan(vv);
			low[u]=min(low[u],low[vv]);
		}else if(ins[vv]){
			low[u]=min(low[u],dfn[vv]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		int vv;
		do{
			vv=s.top();
			s.pop();
			ins[vv]=false;
			scc[vv]=cnt;
			nw[cnt]+=w[vv];
			nv[cnt]+=v[vv];
		}while(u!=vv);
	}
}
void tree_dp(int u){
	for(int j=0;j<=m;++j)dp[u][j]=0;
	for(int j=nw[u];j<=m;++j)dp[u][j]=nv[u];
	for(int v:tadj[u]){
		tree_dp(v);
		for(int j=m;j>=nw[u];--j){
			for(int k=0;k<=j-nw[u];++k){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]!=0)
			adj[d[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(d[i]!=0&&scc[i]!=scc[d[i]])
			tadj[scc[d[i]]].push_back(scc[i]);
	for(int i=1;i<=cnt;i++)
		b[i]=true;
	for(int i=1;i<=cnt;i++)
		for(int vv:tadj[i])
			b[vv]=false;
	int tdp[M]={0};
	for(int i=1;i<=cnt;i++){
		if(b[i]){
			tree_dp(i);
			for(int j=m;j>=0;j--)
				for(int k=0;k<=j;k++)
					tdp[j]=max(tdp[j],tdp[j-k]+dp[i][k]);
		}
	}
	cout<<tdp[m];
	return 0;
}
