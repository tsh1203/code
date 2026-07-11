#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+5;
int n;
int ch[N][30],cnt,f[N];
int ci(char c){return c-'a';}
void insert(string s){
	int u=0;
	for(int i=s.length()-1;i>=0;i--){
		if(!ch[u][ci(s[i])])ch[u][ci(s[i])]=++cnt;
		u=ch[u][ci(s[i])];
	}
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		insert(s);
	}
	cout<<cnt;
	return 0;
}
