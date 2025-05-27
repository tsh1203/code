#include<bits/stdc++.h>
using namespace std;
int w[1005],v[1005];
int f[205][2005];
int main()
{
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		int p;
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=m;i++) 
	{
		for(int j=t;j>=0;j--)  
		{
			if(j>=w[i])
			{
				f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]);
			}  
			else
			{
				f[i][j]=f[i-1][j];
			}              
		}
	}
	
	cout<<f[m][t];
	return 0;
}
