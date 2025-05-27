#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m; 
int a[10004],f[10004];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	memset(f,127,sizeof(f));
	f[0]=0;
	a[0]=2*m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i]=min(f[i],f[i-j]+a[j]);
		}
	}
	cout<<f[n]-m;
	return 0;
}
