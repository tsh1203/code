#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int f[1003][31],t,w,a,ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>w;
	for(int i=1;i<=t;i++)
	{
		cin>>a;
		for(int j=0;j<=w;j++)
		{
			if(j==0)f[i][j]=f[i-1][j];
			else f[i][j]=max(f[i-1][j],f[i-1][j-1]);
			if(j%2+1==a)f[i][j]++;
		}
	}
	for(int i=0;i<=w;i++)
	{
		ans=max(ans,f[t][i]);
	}
	cout<<ans;
	return 0;
}
