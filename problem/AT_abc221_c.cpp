#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
string st,x=" chokudai";
int f[100005][300];
signed main()
{
	cin>>st;
	st="0"+st;
	int n=st.size();
	for(int i=0;i<=n;i++)f[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=8;j++)
		{
			f[i][j]=f[i-1][j];
			if(x[j]==st[i])
				f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
		}
	}
	cout<<f[n][8];
	return 0;
}
//I think somebody will play florr this night.
//T1 is so easy.
//gg
