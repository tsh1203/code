#include<bits/stdc++.h>
#define endl "\n"
#define mem(a) memset((a),0,sizeof((a)))
using namespace std;
const int N=2e5+5;
int tot,ch[N][70];
queue<int>q;
int fail[N],flag[N],tail[N],cnt[N];
int ans[N];
int Map[N];
vector<int>edg[N];
int ci(char c){return c-'a';}
void init(){
	mem(ch),mem(fail),mem(cnt);
	tot=0;
}
void insert(string s,int num){
	int r=0,l=s.length();
	for(int i=0;i<l;i++){
		int d=ci(s[i]);
		if(!ch[r][d])
			ch[r][d]=++tot;
		r=ch[r][d];
	}
	if(!flag[r])flag[r]=num;
	Map[num]=flag[r];
}
void build(){
	for(int i=0;i<26;i++){
		if(ch[0][i]){
			fail[ch[0][i]]=0;
			edg[0].push_back(ch[0][i]);
			q.push(ch[0][i]);
		}
	} 
	while(q.size()){
		int p=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int son=ch[p][i];
			if(son){
				fail[son]=ch[fail[p]][i];
				edg[fail[son]].push_back(son); 
				q.push(son);
			}
			else{
				ch[p][i]=ch[fail[p]][i];
			}
		} 
	} 
}

void found(string s){
	int u=0,an=0;
	for(int i=0;i<s.length();i++){
		u=ch[u][ci(s[i])];
		cnt[u]++;
	}
}
void dfs(int u){
	for(auto v:edg[u]){
		dfs(v);
		cnt[u]+=cnt[v];
	}
	ans[flag[u]]=cnt[u];
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		insert(s,i);
	}
	build();
	string t;
	cin>>t;
	found(t);
	dfs(0);
	for(int i=1;i<=n;i++)cout<<ans[Map[i]]<<endl;
	return 0;
}
