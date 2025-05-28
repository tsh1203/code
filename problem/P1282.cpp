#include<bits/stdc++.h>
using namespace std;
int n,ma,sum,ans;
int a[1003],b[1003];
int f[1003][6003];
int main()
{
	memset(f,127,sizeof(f));
	f[0][0]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=(a[i]+b[i]);
		ma+=max(a[i],b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=ma;j>=1;j--)
		{
			if(j>=a[i])f[i][j]=min(f[i][j],f[i-1][j-a[i]]);
			if(j>=b[i])f[i][j]=min(f[i][j],f[i-1][j-b[i]]+1);
		}
	}
	for(int i=sum/2;i>0;i--)
	{
		if(min(f[n][i],f[n][sum-i])<1e9)
		{
			cout<<min(f[n][i],f[n][sum-i]);
			return 0;
		}
	}
	return 0;
}
