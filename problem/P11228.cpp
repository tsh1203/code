#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
int ma[1003][1003];
int b[1003][1003];
int sum=0;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		memset(b,0,sizeof(b));
		sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='.')ma[i][j]=1;
				else ma[i][j]=0;
			}
		}
		b[x][y]=1;
		sum++;
		for(int i=1;i<=k;i++)
		{
			if(d==0&&ma[x][y+1]&&y+1<=m)
			{
				if(b[x][y+1]==0)
				{
					sum++;
					b[x][y+1]=1;
				}
				y++;
			}
			else if(d==1&&ma[x+1][y]&&x+1<=n)
			{
				if(b[x+1][y]==0)
				{
					sum++;
					b[x+1][y]=1;
				}
				x++;
			}
			else if(d==2&&ma[x][y-1]&&y-1>0)
			{
				if(b[x][y-1]==0)
				{
					sum++;
					b[x][y-1]=1;
				}
				y--;
			}
			else if(d==3&&ma[x-1][y]&&x-1>0)
			{
				if(b[x-1][y]==0)
				{
					sum++;
					b[x-1][y]=1;
				}
				x--;
			}
			else d=(d+1)%4;
		}
		cout<<sum<<endl;
	}
	return 0;
}
