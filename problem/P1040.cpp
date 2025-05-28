#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
int f[100][100],dp[100][100];
void qwq(int l,int r)
{
	if(l>r)return;
	cout<<dp[l][r]<<" ";
	if(l==r)return;
	qwq(l,dp[l][r]-1);
	qwq(dp[l][r]+1,r);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i][i];
		f[i][i-1]=1;
		dp[i][i]=i;
	}
	for(int l=1;l<n;l++)
	{
		for(int i=1;i+l<=n;i++)
		{
			int j=i+l;
			f[i][j]=f[i+1][j]+f[i][i];
			dp[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					dp[i][j]=k;
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	qwq(1,n);
	return 0;
}
