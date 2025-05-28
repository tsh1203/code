#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int r,g,b,k,ans;
int mi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2)ans*=a,ans%=mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
int C(int a,int b)
{
	if(a==0)return 0;
	if(b==0||b==a)return 1;
	if(b>a/2)b=a-b;
	int ans=1;
	for(int i=a;i>=a-b+1;i--)
	{
		ans*=i,ans%=mod;
	}
	for(int i=1;i<=b;i++)
	{
		ans*=mi(i,mod-2);
		ans%=mod;
	}
	return ans;
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>r>>g>>b>>k;
	int n=r+g+b;
	int ans=C(n-g,r-k)*C(n-r,g-k)%mod*C(b+k,k)%mod;
	cout<<ans;
	return 0;
}
