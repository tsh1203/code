#include<bits/stdc++.h>
using namespace std;

const int N=505;//�󲿵��������
const int M=505;//�Ҳ����������

int n,m,tim;
int mat[M];//�Ҳ���iƥ����󲿵�(0=δƥ��)
int vis[M];//ʱ������
vector<int>g[N];

//��ǰ���Ż�+ʱ����Ż���DFS
bool dfs(int u){
	for(int v:g[u]){
		if(vis[v]==tim)
		    continue;//�����ѷ���
		vis[v]=tim;//���ʱ���
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
	
	//�Ż�1:��������󲿵�˳��
	vector<int> ord(n);
	iota(ord.begin(),ord.end(),1);
	shuffle(ord.begin(),ord.end(),mt19937(random_device{}()));
	
	//�Ż�2:̰�ĳ�ʼƥ��(���ظ�����)
	for(int u:ord){
		for(int v:g[u]){
			if(mat[v]==0){
				mat[v]=u;
				cnt++;
				break;
			}
		}
	}
	
	//�Ż�3:ֻΪδƥ��ĵ����DFS
	vector<bool> f(n+1,false);
	for(int v=1;v<=m;v++){
		if(mat[v]!=0){
			f[mat[v]]=true;
		}
	}
	
	//�Ż�4:�����˳����δƥ���
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
	
	//�Ż�5:��ÿ���󲿵���ڽӱ��������
	for(int i=1;i<=n;i++)
		shuffle(g[i].begin(),g[i].end(),mt19937(random_device{}()));
	
	cout<<kuhn();
	return 0;
}
