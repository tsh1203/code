#include<bits/stdc++.h>
#define int long long
using namespace std;
const int base=131;
const int prime=233317; 
const int mod=1000000007;
int a[10004];
int n,ans=1;
string s;
int hs()
{
	int l=s.size();
	int ans=0;
	for(int i=0;i<l;i++)
		ans=(ans*base+(int)s[i])%mod+prime;
	return ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[i]=hs();
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
