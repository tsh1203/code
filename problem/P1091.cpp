#include<bits/stdc++.h>
using namespace std;    
int dp[200][10];
int a[200];
int main()
{
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j])
				dp[i][0]=max(dp[i][0],dp[j][0]+1);    
		}
	}      
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
		for(int j=1;j<i;j++) 
		{
			if(a[i]<a[j])
				dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,max(dp[i][0],dp[i][1]));
	}
	cout<<n-ans;
	return 0;
}
