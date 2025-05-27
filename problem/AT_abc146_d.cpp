#include <bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,ans=INT_MIN,an[100005],k;
int to[100005],nxt[100005];
int head[100005],a[100005];
void add(int x,int y)
{
	k++;
	to[k]=y;
	nxt[k]=head[x];
	head[x]=k;
	a[x]++,a[y]++;
}
void dfs(int x,int y)
{
	int s=0;
	for(int i=head[x];i;i=nxt[i])
	{
		s++;
		an[i]=s;
		if(s==y)
		{
			s++;
			an[i]=s;
		}
		dfs(to[i],an[i]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		ans=max(ans,max(a[x],a[y]));
	}
	cout<<ans<<endl;
	dfs(1,0);
	for(int i=1;i<n;i++)
	{
		cout<<an[i]<<endl;
	}
	return 0;
}
