#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
string s;
int f[200005];
char ma=0;
int x,sum;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==ma)x=i,sum++;
	}
	int t=n;
	f[n]=n+1;
	for(int i=n-1;i>=1;i--)
	{
		f[i]=t;                             
		if(s[i]>=s[t])t=i;
	}
	if(sum%k)
	{
		for(int i=1;i<=sum/k+1;i++)cout<<ma;
	}
	else
	{
		for(int i=1;i<=sum/k;i++)cout<<ma;
		for(int i=f[x];i<=n;i=f[i])cout<<s[i];
	}
	return 0;
}
