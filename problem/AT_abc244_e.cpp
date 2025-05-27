#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k,s,t,x,sum;
int f[2003][2003][10];
vector<int>e[10000];
void add(int u,int v)
{
	e[v].push_back(u); 
	e[u].push_back(v);
}
int main()
{
	cin>>n>>m>>k>>s>>t>>x;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		add(a,b);
	}
	f[0][s][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<e[j].size();k++)//遍历图 
			{
				int r=e[j][k];
				if(j==x)
				{
					f[i][j][0]+=f[i-1][r][1];
					f[i][j][1]+=f[i-1][r][0];
					f[i][j][0]%=mod;//mod
					f[i][j][1]%=mod;
				}
				else
				{
					f[i][j][0]+=f[i-1][r][0];
					f[i][j][1]+=f[i-1][r][1];
					f[i][j][0]%=mod;
					f[i][j][1]%=mod;
				}
			}
		}
	}
	cout<<f[k][t][0];
	return 0;
}
