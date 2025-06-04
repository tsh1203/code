#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int p=233317; 
const int mod=1000000007;
int n;
string s;
int ha1[2000005],ha2[2000005],base[2000005];
int hash1(int l,int r)
{
	return (ha1[r]+mod-ha1[l-1]*base[r-l+1]%mod)%mod;
}
int hash2(int l,int r)
{
	return (ha2[l]+mod-ha2[r+1]*base[r-l+1]%mod)%mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	s='#'+s;
	base[0]=1;
	for(int i=1;i<=2*n;i++)
	{
		base[i]=base[i-1]*p;
		base[i]%=mod;
	}
	for(int i=1;i<=2*n;i++)
	{
		ha1[i]=ha1[i-1]*p+s[i]-48;
		ha1[i]+=mod,ha1[i]%=mod;
	}
	for(int i=2*n;i>0;i--)
	{
		ha2[i]=ha2[i+1]*p+s[i]-48;
		ha2[i]+=mod,ha2[i]%=mod;
	}
	for(int i=0;i<=n;i++)
	{
		if((hash1(1,i)*base[n-i]+hash1(i+n+1,n+n))%mod==hash2(i+1,i+n))
		{
			for(int j=i+n;j>i;j--)
			{ 
				cout<<s[j]; 
			} 
			cout<<endl<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
