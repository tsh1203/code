#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
//rp++
struct edge
{
	int to,w;//to,是否为移动
};
struct no
{
	int num,p;
};
bool operator < (no a,no b)
{
	return a.p > b.p;
}
int n,m,k; 
int f[400005],b[400005];
vector<edge>e[400005];
priority_queue<no>q;
void add(int u,int v,int w)
{
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(f,127,sizeof(f));
	f[1]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(w)add(u,v,1);
		else add(u+n,v+n,1);
	}
	for(int i=1;i<=k;i++)
	{
		int u;
		cin>>u;
		//换层
		add(u,u+n,0);
	}
	q.push({1,0});
	while(!q.empty())
	{
		int x=q.top().num;
		q.pop();
		b[x]=1;
		for(auto i:e[x])
		{
			if(f[x]+i.w<f[i.to]&&b[i.to]==0)
			{
				f[i.to]=f[x]+i.w;
				q.push({i.to,f[i.to]});
				b[i.to]=1;
			}
		}
		
	}
	if(f[n]>1e12&&f[2*n]>1e12)cout<<-1;
	else cout<<min(f[n],f[2*n]);
	return 0;
}
