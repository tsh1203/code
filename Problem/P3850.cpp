#include<bits/stdc++.h>
#include<ext/rope>
#define endl "\n"
using namespace std;
using namespace __gnu_cxx;
rope<int>r;
string s[1000006];
int cnt;
int main(){
	int n,m,q;
	cin>>n;
	while(n--){
		cin>>s[r.size()];
		r.push_back(r.size());
		++cnt;
	}
	cin>>m;
	while(m--){
		int x;
		cin>>s[r.size()]>>x;
		r.insert(x,r.size());
		++cnt;
	}
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<s[r[x]]<<endl;
	}
	return 0;
}
