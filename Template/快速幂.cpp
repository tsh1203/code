#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int fp(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,p;
	cin>>a>>b>>p;
	int s=fp(a, b, p);
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<s;
	return 0;
}    
