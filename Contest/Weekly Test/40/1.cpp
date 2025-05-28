#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,k,h,w;
int a[302][302],b[302],c[302];
int sum,su,ans[302][302];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k>>h>>w;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(c[a[i][j]]==0)su++;
			c[a[i][j]]++;
		}
	}
	for(int i=1;i<=n-h+1;i++)
	{
		for(int j=1;j<=m-w+1;j++)
		{
			if(j==1)
			{
				sum=su;
				for(int i=1;i<=k;i++)
				{
					b[i]=c[i];
				}
				for(int x=i;x<=i+h-1;x++)
				{
					for(int y=1;y<=w;y++)
					{
						b[a[x][y]]--;
						if(b[a[x][y]]==0)sum--;
					}
				}
			}
			else
			{
				for(int x=i;x<=i+h-1;x++)
				{
					b[a[x][j-1]]++;
					if(b[a[x][j-1]]==1)sum++;
				}
				for(int x=i;x<=i+h-1;x++)
				{
					b[a[x][j+w-1]]--;
					if(b[a[x][j+w-1]]==0)sum--;
				}
			}
			ans[i][j]=sum;
		}
	}
	for(int i=1;i<=n-h+1;i++)
	{
		for(int j=1;j<=m-w+1;j++)
		{
			cout<<ans[i][j];
			if(j!=m-w+1)cout<<" ";
		}
		if(i!=n-h+1)cout<<endl;
	}
	return 0;
}
