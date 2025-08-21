#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e4+5;
const int INF=0x3f3f3f3f;

//n,m:左右部点数
//dx,dy:左右部点的层次深度
//mx,my:左右部点的匹配对象
//vis:访问标记
//g:邻接表
int n,m;
int dx[N],dy[N],mx[N],my[N];
bool vis[N];
vector<int> g[N];

//BFS构建层次图
bool bfs(){
	queue<int> q;
	bool found=false;
	
	//初始化左部点层次
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy));
	
	//将所有未匹配的左部点加入队列，层次设为1
	for(int i=1;i<=n;i++){
		if(mx[i]==0){
			dx[i]=1;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dy[v]==0){//右部点v还没有被设置层次
				dy[v]=dx[u]+1;//设置v的层次
				if(my[v]==0)//v未匹配，找到增广路
					found=true;
				else{//v已匹配，继续探索
					dx[my[v]]=dy[v]+1;
					q.push(my[v]);
				}
			}
		}
	}
	
	return found;
}

//DFS寻找增广路
bool dfs(int u){
	for(int v:g[u]){
		//层次必须连续，且避免重复访问
		if(!vis[v]&&dy[v]==dx[u]+1){
			vis[v]=true;
			//如果v未匹配，或者v的匹配点可以找到新的增广路
			if(my[v]==0||dfs(my[v])){
				mx[u]=v;
				my[v]=u;
				return true;
			}
		}
	}
	return false;
}

int hopcroft_karp(){
	int cnt=0;
	memset(mx,0,sizeof(mx));
	memset(my,0,sizeof(my));
	
	//优化:先贪心初始匹配
	for(int u=1;u<=n;u++){
		for(int v:g[u]){
			if(my[v]==0){
				mx[u]=v;
				my[v]=u;
				cnt++;
				break;
			}
		}
	}
	
	//主算法：多轮BFS+DFS
	while(bfs()){//BFS构建层次图
		memset(vis,false,sizeof(vis));
		//对所有未匹配的左部点进行DFS
		for(int i=1;i<=n;i++)
			if(mx[i]==0&&dfs(i))
				cnt++;
	}
	
	return cnt;
}

int main(){
	int e;
	cin>>n>>m>>e;
	
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	
	cout<<hopcroft_karp();
	return 0;
}
