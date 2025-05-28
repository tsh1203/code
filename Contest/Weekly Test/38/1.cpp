#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int t,c[100];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(c,0,sizeof(c));
		string s;
		cin>>s;
		int l=s.length();
		for(int i=0;i<l;i++)
		{
			c[s[i]-'a'+1]++;
		}
		int ma=INT_MIN;
		for(int i=1;i<=26;i++)
		{
			ma=max(ma,c[i]);
		}
		int ans=max(l%2,ma*2-l);
		cout<<ans<<endl;
	}
	return 0;
}
