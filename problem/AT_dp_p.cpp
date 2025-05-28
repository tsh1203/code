#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
int n,x,y,f[100005][3];
vector<int>e[100005];
void qwq(int x,int y)
{
	f[x][0]=1;
	f[x][1]=1;
	for(int i=0;i<e[x].size();i++)
	{
		int ne=e[x][i];
		if(ne==y)continue;
		qwq(ne,x);
		f[x][1]*=f[ne][0];
		f[x][1]%=mod;
		f[x][0]*=(f[ne][1]+f[ne][0])%mod;
		f[x][0]%=mod;
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	qwq(1,1);
	int ans=(f[1][0]+f[1][1])%mod;
	cout<<ans;
	return 0;
}
