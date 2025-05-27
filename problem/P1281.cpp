#include<bits/stdc++.h>
using namespace std;
int m,k,p[1000],dp[1000][1000];
void fun(int x,int to)
{
	if(!to)return ;
	int sum=0,t=1;
	for(int i=to;i>=1;i--)
	{
		sum+=p[i];
		if(sum>x)
		{
			sum-=p[i];
			t+=i;
			break;
		}
	}
	fun(x,t-1);
	cout<<t<<" "<<to<<endl;
}
int main()
{
	memset(dp,127,sizeof(dp));
	cin>>m>>k;
	dp[1][0]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i];
		dp[1][i]=dp[1][i-1]+p[i];
	}
	
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],max(dp[i-1][k],dp[1][j]-dp[1][k]));
			}
		}
	}
	fun(dp[k][m],m);
	return 0;
}
