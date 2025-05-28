#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,p,cnt,tim;
int head[1000006];
int st[1000006],en[1000006],a[1000006],s[1000006];
struct ed
{
	int v,nxt;
}e[2000006];
int lb(int x)
{
	return x&-x;
}
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	st[u]=++tim;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			dfs(v,u);
		}
	}
	en[u]=tim;
}
void pchange(int x,int y)
{
	for(int i=x;i<=n;i+=lb(i))
	{
		s[i]+=y;
	}
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i;i-=lb(i))
	{
		ans+=s[i];
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(p,0);
	for(int i=1;i<=n;i++)
	{
		pchange(st[i],a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		cin>>op>>x;
		if(op==1)
		{
			cin>>y;
			pchange(st[x],y);
		}
		else
		{
			cout<<sum(en[x])-sum(st[x]-1)<<endl;
		}
	}
	return 0;
}
