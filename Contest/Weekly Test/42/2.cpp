#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,ans,a[1003][1003];
int f[1003][2][2];
bool pd(int h,int x,int y)
{
	for(int i=1;i<=m;i++)
		if(a[h][i]!=(a[h-1][i]^x)&&a[h][i]!=a[h][i-1]&&a[h][i]!=(a[h+1][i]^y)&&a[h][i]!=a[h][i+1])
			return 0;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,-1,sizeof(a));
	memset(f,127,sizeof(f));
	f[1][0][0]=0,f[1][1][0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	
	for(int i=2;i<=n+1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(pd(i-1,k^1,j^k))f[i][j][k]=min(f[i][j][k],f[i-1][k][1]+j);
				if(pd(i-1,k^0,j^k))f[i][j][k]=min(f[i][j][k],f[i-1][k][0]+j);
			}
		}
	}
	if(min(f[n+1][0][0],f[n+1][0][1])>n)cout<<-1;
	else cout<<min(f[n+1][0][0],f[n+1][0][1]);
	return 0;
}
