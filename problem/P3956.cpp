#include <bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MAX;
int a[105][105];
bool b[105][105];
int d[105][105],f[4][2]={{0,1},{1,0},{-1,0},{0,-1}},X,Y,c;
void dfs(bool flag,int h,int x,int y,int c)
{
	if(d[x][y]<=h)return;
	if(h>=ans)return;
	d[x][y]=h;
	if(x==n&&y==n)
	{
		ans=h;
	}
	for(int i=0;i<4;i++)
	{
		int dx=x+f[i][0],dy=y+f[i][1];
		if(dx<1||dy<1||dx>n||dy>n||b[dx][dy])
		{
			continue;
		}
		if(flag&&a[dx][dy]==0)
		{
			continue;
		}
		b[dx][dy]=1;
		if(a[dx][dy]==0)
		{
			dfs(1,h+2,dx,dy,c);
		}
		else if(a[dx][dy]==c)
		{
			dfs(0,h,dx,dy,c);
		}
		else if(a[dx][dy]!=c)
		{
			dfs(0,h+1,dx,dy,a[dx][dy]);
		}
		b[dx][dy]=false;
	}
}
int main() 
{
	memset(d,127,sizeof(d));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>X>>Y>>c;
		a[X][Y]=c+1;
	}
	dfs(0,0,1,1,a[1][1]);
	if(ans==INT_MAX)
	{
		cout<<"-1";
	}
	else cout<<ans;
	return 0;
}
