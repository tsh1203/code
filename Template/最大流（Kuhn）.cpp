#include<bits/stdc++.h>
using namespace std;

const int N=505;//左部点最大数量
const int M=505;//右部点最大数量

int n,m,tim;
int mat[M];//右部点i匹配的左部点(0=未匹配)
int vis[M];//时间戳标记
vector<int>g[N];

//当前弧优化+时间戳优化的DFS
bool dfs(int u){
	for(int v:g[u]){
		if(vis[v]==tim)
		    continue;//本轮已访问
		vis[v]=tim;//标记时间戳
		if(mat[v]==0||dfs(mat[v])){
			mat[v]=u;
			return true;
		}
	}
	return false;
}

int kuhn(){
	int cnt=0;
	memset(mat,0,sizeof(mat));
	memset(vis,0,sizeof(vis));
	tim=0;
	
	//优化1:随机打乱左部点顺序
	vector<int> ord(n);
	iota(ord.begin(),ord.end(),1);
	shuffle(ord.begin(),ord.end(),mt19937(random_device{}()));
	
	//优化2:贪心初始匹配(不重复计数)
	for(int u:ord){
		for(int v:g[u]){
			if(mat[v]==0){
				mat[v]=u;
				cnt++;
				break;
			}
		}
	}
	
	//优化3:只为未匹配的点进行DFS
	vector<bool> f(n+1,false);
	for(int v=1;v<=m;v++){
		if(mat[v]!=0){
			f[mat[v]]=true;
		}
	}
	
	//优化4:按随机顺序处理未匹配点
	vector<int> un;
	for(int u:ord){
		if(!f[u]){
			un.push_back(u);
		}
	}
	shuffle(un.begin(),un.end(),mt19937(random_device{}()));
	
	for(int u:un){
		tim++;
		if(dfs(u))
			cnt++;
	}
	
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int e;
	cin>>n>>m>>e;
	
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	
	//优化5:对每个左部点的邻接表随机打乱
	for(int i=1;i<=n;i++)
		shuffle(g[i].begin(),g[i].end(),mt19937(random_device{}()));
	
	cout<<kuhn();
	return 0;
}
