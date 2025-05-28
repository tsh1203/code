#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
#define gcd __gcd
using namespace std;
int k,n;
set<int>st;
int mo(int x,int y)
{
	int s=0;
	while(x%y==0&&x>1)
	{
		x/=y;
		s++;
	}
	return s;
}
void init()
{
	for(int i=1;i<=sqrt(k);i++)
	{
		if(k%i==0)
		{
			st.insert(i);
			st.insert(k/i);
		}
	}
	st.erase(1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>k;
	n=k;
	init();
	int ma=-1;
	for(auto i:st)
	{
		if(n%i==0)
		{
			int cnt=mo(n,i),x=0;
			for(int j=1;j<=cnt;j++)n/=i;
			while(cnt>0)
			{
				++x;
				cnt-=mo(x*i,i);
			}
			ma=max(ma,x*i);
		}
		i++;
	}
	if(ma==-1)cout<<k;
	else cout<<ma;
	return 0;
}
