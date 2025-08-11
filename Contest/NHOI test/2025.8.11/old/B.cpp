#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+4;
int n,q;
int v[N],up[N],down[N];
//1 ≤ N ≤10000 
//1 ≤ value[i], up[i], down[i] ≤ 500
//1 ≤ Q ≤ 5 × 10^5
//0 ≤ ini ≤ 10^9
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>up[i]>>down[i];
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		for(int i=1;i<=n;i++){
			if(x<=v[i])x+=up[i];
			else x-=down[i];
			x=max(x,0ll);
		}
		cout<<x<<endl;
 	}
	return 0;
}
