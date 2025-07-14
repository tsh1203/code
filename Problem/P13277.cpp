#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t,k1,k2,ans=-1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>k1>>k2;
	while(t--){
		int a,x,y;
		cin>>a>>x>>y;
		int te=a-x*k1-y*k2;
		if(x&&y)te=-1;
		if(te>=0)ans=max(ans,te);
	}
	cout<<ans;
	return 0;
}
