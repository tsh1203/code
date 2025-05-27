#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
__int128 f[100][100],ans;
string an;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k+j-1<=m;k++)
			{
				int l=k+j-1;
				f[k][l]=max(f[k+1][l]+a[i][k],f[k][l-1]+a[i][l])*2;
			}
		}
		ans+=f[1][m];
	}
	while(ans)
	{
		an=(char)(ans%10+'0')+an;
		ans/=10;
	}
	if(an=="") cout<<0;
	else cout<<an;
	return 0;
}
