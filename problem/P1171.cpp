#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=21,M=(1<<20)+10;
int n;
int e[N][N],f[M][N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(f,127,sizeof(f));
	f[1][1]=0;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>e[i][j];
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>>(j-1)&1)
			{
				for(int k=1;k<=n;k++)
				{
					f[i][j]=min(f[i][j],f[i^(1<<(j-1))][k]+e[k][j]);
				}
			}
		}
	}
	
	int ans=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,f[(1<<n)-1][i]+e[i][1]);
	}
	cout<<ans;
	return 0;
	
}
