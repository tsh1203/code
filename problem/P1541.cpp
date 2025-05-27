#include<bits/stdc++.h>
using namespace std;
int n,m,x[10],a[1000],b,f[50][50][50][50];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		x[b]++;
	}
	for(int i=0;i<=x[1];i++)
	{
		for(int j=0;j<=x[2];j++)
		{
			for(int k=0;k<=x[3];k++)
			{
				for(int v=0;v<=x[4];v++)
				{
					if(i+j+k+v==0)
					{
						f[0][0][0][0]=a[1];
						continue;
					}
					int sb=1+1*i+2*j+3*k+4*v;
					f[i][j][k][v]=0;
					if(i>0&&f[i-1][j][k][v]+a[sb]>f[i][j][k][v])
					{
						f[i][j][k][v]=a[sb]+f[i-1][j][k][v];
					}
					if(j>0&&f[i][j-1][k][v]+a[sb]>f[i][j][k][v])
					{
						f[i][j][k][v]=a[sb]+f[i][j-1][k][v];
					}
					if(k>0&&f[i][j][k-1][v]+a[sb]>f[i][j][k][v])
					{
						f[i][j][k][v]=a[sb]+f[i][j][k-1][v];
					}
					if(v>0&&f[i][j][k][v-1]+a[sb]>f[i][j][k][v])
					{
						f[i][j][k][v]=a[sb]+f[i][j][k][v-1];
					}
				}
			}
		}
	}
	cout<<f[x[1]][x[2]][x[3]][x[4]];
	return 0;
}
