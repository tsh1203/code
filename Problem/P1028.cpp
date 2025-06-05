#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,f[1003];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<=i/2;j++)
		{
			f[i]+=f[j];
		}
	}
	cout<<f[n];
	return 0;
}
