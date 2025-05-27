#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		ans+=k-m;
	}
	cout<<max(k-ans,(int)0);
	return 0;
}
