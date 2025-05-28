#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
struct edge
{
	int from,to,next;
}a[400005];
int n,k;
map<int,int>b,pre;
queue<int>q;
int ans;
void add(int u,int v)
{
	k++;
	a[k].from=u;
	a[k].to=v;
	a[k].next=pre[u];
	pre[u]=k;
} 
void bfs()
{
	q.push(1);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		b[x]=1;
		ans=max(ans,x);
		for(int j=pre[x];j;j=a[j].next)
		{
			int to=a[j].to;
			if(!b[to])
			{
				b[to]=1;
				q.push(to);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	bfs();
	cout<<ans;
	return 0;
}
