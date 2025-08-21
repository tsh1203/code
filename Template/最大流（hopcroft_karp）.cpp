#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e4+5;
const int INF=0x3f3f3f3f;

//n,m:���Ҳ�����
//dx,dy:���Ҳ���Ĳ�����
//mx,my:���Ҳ����ƥ�����
//vis:���ʱ��
//g:�ڽӱ�
int n,m;
int dx[N],dy[N],mx[N],my[N];
bool vis[N];
vector<int> g[N];

//BFS�������ͼ
bool bfs(){
	queue<int> q;
	bool found=false;
	
	//��ʼ���󲿵���
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy));
	
	//������δƥ����󲿵������У������Ϊ1
	for(int i=1;i<=n;i++){
		if(mx[i]==0){
			dx[i]=1;
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dy[v]==0){//�Ҳ���v��û�б����ò��
				dy[v]=dx[u]+1;//����v�Ĳ��
				if(my[v]==0)//vδƥ�䣬�ҵ�����·
					found=true;
				else{//v��ƥ�䣬����̽��
					dx[my[v]]=dy[v]+1;
					q.push(my[v]);
				}
			}
		}
	}
	
	return found;
}

//DFSѰ������·
bool dfs(int u){
	for(int v:g[u]){
		//��α����������ұ����ظ�����
		if(!vis[v]&&dy[v]==dx[u]+1){
			vis[v]=true;
			//���vδƥ�䣬����v��ƥ�������ҵ��µ�����·
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
	
	//�Ż�:��̰�ĳ�ʼƥ��
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
	
	//���㷨������BFS+DFS
	while(bfs()){//BFS�������ͼ
		memset(vis,false,sizeof(vis));
		//������δƥ����󲿵����DFS
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
