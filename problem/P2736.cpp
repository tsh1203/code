#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[602],f[602][602];
int main()
{
	cin>>n>>t>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=t;k>=a[i];k--)
			{
				f[j][k]=max(f[j][k],max(f[j-1][t]+1,f[j][k-a[i]]+1));
			}
		}
	}
	int ma=0;
	for(int i=1;i<=m;i++) 
	{
		for(int j=1;j<=t;j++)
		{
			ma=max(ma,f[i][j]);
		}
	}
	cout<<ma;
	return 0;
}
