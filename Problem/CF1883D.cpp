#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
struct no{
	int v;
	bool operator < (const no &a)const{
		return a.v<v;
	}
};
multiset<int>R;
multiset<no>L;
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		char c;int l,r;
		cin>>c>>l>>r;
		if(c=='+'){
			L.insert({l});
			R.insert(r);
		}
		else{
			L.erase(L.find({l}));
			R.erase(R.find(r));
		}
		if(L.size()){
			if((*L.begin()).v<=(*R.begin())){cout<<"NO\n";}
			else cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
