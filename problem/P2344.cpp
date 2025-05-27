#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000009;
int n,a[100001],f[100001];
bool b[100001];
int ans;
priority_queue<int,vector<int>,greater<int>>e;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	e.push(0);
	while(!e.empty())
	{
		int k=0,now=e.top();
		for(int i=now+1;i<=n;i++)
		{
			k+=a[i];
			if(k>=0)
			{
				f[i]+=f[now];
				f[i]%=mod;
				if(!b[i])
				{
					e.push(i);
					b[i]=1;
				}
			}
		}
		e.pop();
	}
	cout<<f[n];
	return 0;
}
