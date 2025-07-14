#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
int a[100005],b[100005],c[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>a[i];
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>b[i];
	
	for(int i=1;i<=k;i++)
		cin>>c[i];
	
	int s,t;
	cin>>s>>t;
	
	int ans=0;
	for(int i=s;i<t;i++)
		ans+=a[i];
	
	for(int i=1;i<=k;i++)
		if(b[i]>s&&b[i]<t)
			ans+=c[i];
	
	cout<<ans;
	
	return 0;
}
