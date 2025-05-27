#include<bits/stdc++.h>
using namespace std;
long long f[105][105];
long long a[105][105];
int dx[10]={0,0,0,-1,1},dy[10]={0,1,-1,0,0};
long long n,m,sum;
int dfs(int x,int y)
{
	if (f[x][y]) return f[x][y];
	int sum=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(x>0&&y>0&&x<=n&&y<=m&&a[xx][yy]>a[x][y])sum=max(sum,dfs(xx,yy));
	}
	f[x][y]=sum+1;
	return f[x][y];
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (f[i][j]==0) f[i][j]=dfs(i,j);
			sum=max(sum,f[i][j]);
		}
	}
	cout<<sum;
	return 0;
}
