#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int a[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,ma=INT_MIN,ans=0;
		cin>>n>>k;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]),ans+=ma; 
		ma*=n;
		if(n==2)
		{
			if(k%2==0)cout<<max(a[1],a[2])+a[1];
			else cout<<max(a[1],a[2])+a[2];
		}
		else if(k==0)cout<<ans;
		else cout<<ma;
		cout<<endl;//qwq
		
	}
	return 0;
}
