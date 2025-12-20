#include<bits/stdc++.h>
#define endl "\n"
#define mem(a) memset((a),0,sizeof((a)))
using namespace std;
const int N=2e4+5;
int tot,ch[N][70];
queue<int>q;
int fail[N],flag[N],tail[N],cnt[N];
int ans[N],Map[N];
string s[200];
int ci(char c){return c-'a';}
void init(){
	mem(ch),mem(fail),mem(cnt),mem(flag);
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
	flag[r]=num;
}
void build(){
	for(int i=0;i<26;i++){
		if(ch[0][i]){
			fail[ch[0][i]]=0;
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
		for(int j=u;j;j=fail[j]){
			if(flag[j])cnt[flag[j]]++;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1){
		init();
		int n,m;
		cin>>n;
		if(n==0)break;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			insert(s[i],i);
		}
		build();
		string t;
		cin>>t;
		found(t);
		int mx=-1;
		for(int i=1;i<=n;i++)mx=max(mx,cnt[i]);
		cout<<mx<<endl;
		for(int i=1;i<=n;i++)
			if(cnt[i]==mx)
				cout<<s[i]<<endl; 
	}
	return 0;
}
