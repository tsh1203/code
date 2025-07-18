#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,q;
int d1,d2;
int cnt;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(d2<m&&d1<m){
			if(x>0)d2+=x,cnt++;
			else d1-=x;
		}
	}
	while(q--){
		int x;
		cin>>x;
		if(d2+cnt*x>=m)cout<<"Yes";
		else{
			if(d1<m)cout<<"Tie";
			else cout<<"No";
		}
		cout<<endl;
	}
	return 0;
}
