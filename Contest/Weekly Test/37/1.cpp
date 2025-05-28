#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,an,ans=INT_MAX;
int f[102][102],num[102];
string s[102];
int rp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	rp++;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			f[i][s[i][j]-'0']=j;
		}
	}
	for(int i=0;i<=9;i++)
	{
		an=0;
		memset(num,0,sizeof(num));
		
		for(int j=1;j<=n;j++)
		{
			num[f[j][i]]++;
		}
		
		for(int j=0;j<=9;j++)
		{
			an=max(an,j+(num[j]-1)*10);
		}
		
		ans=min(ans,an);
	}
	cout<<ans;
	return 0;
}
//qwq
