#include<bits/stdc++.h>
using namespace std;
long long a[2001],x[2001],n,m,ma,mi=1000000000000000;
long long f[201][201][21],g[201][201][21]; 
int main()
{
	cin>>n>>m;
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=100;j++)
		{
			for (int k=1;k<=10;k++)
				g[i][j][k]=10000000000;
		}
	} 
	for (int i=1;i<=n;i++)
	{
		cin>>x[i];
		a[i]+=a[i-1]+x[i];
	}
	for (int i=n+1;i<=n*2;i++)
		a[i]+=a[i-1]+x[i-n]; 
	for (int i=1;i<=n*2;i++)
	{
		for (int j=1;j<=n*2;j++)
		{
			f[i][j][1]=(a[j]-a[i-1]+100000000000)%10;
			g[i][j][1]=(a[j]-a[i-1]+100000000000)%10;
		}
	}
	
	for (int i=1;i<=n*2;i++) 
	{
		for (int j=i+1;j<=n*2;j++)
		{
			for (int l=2;l<=m;l++)
			{
				for (int k=i;k<j;k++)
				{
					f[i][j][l]=max(f[i][j][l],f[i][k][l-1]*f[k+1][j][1]);
					g[i][j][l]=min(g[i][j][l],g[i][k][l-1]*g[k+1][j][1]);
				}
			}
		}
	}
	for (int i=1;i<=n;i++) 
	{
		ma=max(ma,f[i][i+n-1][m]);
		mi=min(mi,g[i][i+n-1][m]);  
	}
	cout<<mi<<endl<<ma;
	return 0; 
}
