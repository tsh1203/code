#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,t;
int r1,c1,r2,c2;
int f[102][102][102],ma[102][102];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0};
int dfs(int x,int y,int t)
{
	if(f[x][y][t]!=-1)return f[x][y][t];
	if(t==0)
	{
		if(x==r2&&y==c2)return f[x][y][t]=1;
		return f[x][y][t]=0;
	}
	int cou=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&ma[xx][yy])
		{
			cou+=dfs(xx,yy,t-1);
		}
	}
	return f[x][y][t]=cou;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>t;
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='*')ma[i][j]=0;
			else ma[i][j]=1;
		}
	}
	cin>>r1>>c1>>r2>>c2;
	cout<<dfs(r1,c1,t);
	return 0;
}
