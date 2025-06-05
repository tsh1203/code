#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,k;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n>k)n-=k++;
	if(k&1)cout<<k+1-n<<"/"<<n;
	else cout<<n<<"/"<<k+1-n;
	return 0;
}
