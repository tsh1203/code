#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int l,r,ans=0;
	cin>>l>>r;
	for(int i=1;i<n;i++)
	{
		cin>>l;
		ans+=max(l-r-m,(int)0);
		cin>>r;
	}
	cout<<ans;
	return 0;
}
