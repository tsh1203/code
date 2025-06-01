#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if((n+m-1)%4==2)cout<<1<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}
