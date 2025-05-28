#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int s[6003],n,dp[6003][10];
int r,xx[6003],yy[6003];
void qwq(int x)
{
	for(int i=yy[x];i;i=xx[i])
	{
		qwq(i);
		dp[x][1]=max(max(dp[x][1],dp[x][1]+dp[i][0]),dp[i][0]);
		dp[x][0]=max(max(dp[x][0],dp[i][1]+dp[x][0]),max(dp[i][1],dp[i][0]));
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dp[i][1];
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==b&&a==0)break;
		s[a]++;
		xx[a]=yy[b];
		yy[b]=a;
	}
	for(int i=1;i<=n;i++)
	{
		if(!s[i])
		{
			r=i;
			break;
		}
	}
	qwq(r);
	cout<<max(dp[r][0],dp[r][1]);
	return 0;
}
