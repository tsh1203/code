#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=102;
int n,m;
int f[N][N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)f[i][j]=1e9;
	else f[i][j]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		f[x][y]=f[y][x]=min(f[x][y],z);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(f[i][k]!=1e9)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
	
}
