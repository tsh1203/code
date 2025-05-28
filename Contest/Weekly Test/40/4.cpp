#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int n,k,c;
int f[1000006];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>c;
	f[1]=c;
    for(int i=2;i<=n;i++)
        f[i]=(f[i-1]*2%mod+(c-2)*f[max(1ll,i-k+1)]%mod)%mod;
    cout<<f[n];
	return 0;
}
