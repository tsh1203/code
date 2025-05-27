#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
vector<int>e[100005];
int a[100005],cnt[100005],ans[100005];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int k)
{
	while(x<=n)
	{
		cnt[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=cnt[x];
		x-=lowbit(x);		
	}
	return s;
}
void dfs(int u,int fa)
{
	int k=a[u];
	ans[k]=sum(k-1);
	add(k,1);
	for(auto i:e[u])
	{
		if(i==fa)
			continue;
		dfs(i,u);
	}
	add(k,-1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[t]=i;
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
