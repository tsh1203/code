#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int head[302],nex[302],to[302],top;
int dp[302][302];
void add(int u,int v)
{
	top++;
	nex[top]=head[u];
	to[top]=v;
	head[u]=top;
}
void qwq(int u)
{
	for(int i=head[u];i;i=nex[i])
	{
		qwq(to[i]);
	}
	for(int i=head[u];i;i=nex[i])
	{
		for(int j=m+1;j>0;j--)
		{
			for(int k=0;k<j;k++)
			{
				int v=to[i];
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x>>dp[i][1];
		add(x,i);
	}
	qwq(0);
	cout<<dp[0][m+1];
	return 0;
}
