#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w[10004],v[10004],f[10000007];
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=w[i];j<=m;j++)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[m];
	return 0;
}
