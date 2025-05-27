#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
string s;
int q,a,b,x,y;
signed main()
{
	//log(1e18)=59.7947
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	cin>>q;
	for(int i=0;i<(int)s.length();i++)s[i]-='A';
	while(q--)
	{
		cin>>x>>y;
		if(x>60)//byd玩意,I dont want to see you
		{
			a=0;
			b=y-1;
		}
		else
		{
			a=(y-1)/(1ll<<x);
			b=(y-1)%(1ll<<x);
		}
		int c=(s[a]+x)%3;
		for(int i=b;i>0;i-=(i&-i))
		{
			c++;
			c%=3;
		}
		cout<<(char)(c+'A')<<endl;
	}
	return 0;
}
//累，T1根本不会
