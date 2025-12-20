#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=3e6+5;
int tot,ch[N][70];
queue<int>q;
int fail[N],cnt[N],l;
int ci(char c){return c-'a';}
void insert(string s){
	int r=0,l=s.length();
	for(int i=0;i<l;i++){
		int d=ci(s[i]);
		if(!ch[r][d])
			ch[r][d]=++tot;
		r=ch[r][d];
	}
	cnt[r]++;
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
int found(string s){
	int u=0,an=0;
	for(int i=0;i<s.length();i++){
		u=ch[u][ci(s[i])];
		for(int j=u;cnt[j]!=-1;j=fail[j]){
			an+=cnt[j];
			cnt[j]=-1; 
		}
	}
	return an;
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
		insert(s);
	}
	build();
	string t;
	cin>>t;
	cout<<found(t);
	return 0;
}
