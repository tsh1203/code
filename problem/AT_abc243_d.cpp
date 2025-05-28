#include <bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
stack<int>st;
string s;
int n,x;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')
		{
			if(!st.empty())
			{
				s[st.top()]=' ';
				s[i]=' ';
				st.pop();
			}
		}
		else 
		{
			st.push(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')x*=2;
		else if(s[i]=='R')x=x*2+1;
		else if(s[i]=='U')x/=2;
	}
	cout<<x;
	return 0;
}
