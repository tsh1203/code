#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("3","Ofast","inline")
#define endl "\n"
using namespace std;
int t,a,s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>a>>s;
		int x=s-a;
		if(x>=a&&((a&x)==a))
		{
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	return 0;
}
