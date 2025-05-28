#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[5010],b[5010];
int f[5010][5010];
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][0]=f[i-1][0]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=max(f[i-1][j]-a[i],f[i-1][j-1]+a[i]);
			if(j%t==0)f[i][j]=max(f[i-1][j]-a[i],f[i-1][j-1]+a[i]+b[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[n][i]);
	cout<<ans;
	return 0;
}
