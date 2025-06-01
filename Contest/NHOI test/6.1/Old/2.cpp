#include<bits/stdc++.h>
//#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,c,d[100005];
vector<pair<int,int>>e[100005];
int nxt[100005],nxtw[100005],sum[100005],cnt;
int uu,vv,mx;
void del(int u,int v)
{
	for(int i=0;i<e[u].size();i++)
	{
		if(e[u][i].first==v)e[u][i].first=e[u][i].second=0;
	}
	for(int i=0;i<e[v].size();i++)
	{
		if(e[v][i].first==u)e[v][i].first=e[v][i].second=0;
	}
}
void dfs(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa||v==0)continue;
		d[v]=d[u]+w;
		if(d[v]>d[c])c=v;
		dfs(v,u);
	}
} 
void dfs2(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa||v==0)continue;
		d[v]=d[u]+w;
		if(d[v]>d[c])c=v;
		dfs2(v,u);
		nxt[v]=u;
		nxtw[v]=w;
	}
} 
void prin()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(auto j:e[i])
		{
			if(j.first)cout<<j.first<<","<<j.second<<" ";
		}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)nxt[i]=i;
	
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	//prin();
	dfs(1,0);
	d[c]=0;
	dfs2(c,0);
	int cc=c,ans=INT_MAX;
	while(nxt[c]!=c)
	{
		if(mx<nxtw[c])
		{
			mx=nxtw[c];
			uu=c;
			vv=nxt[c];
		}
		sum[++cnt]=sum[cnt-1]+nxtw[nxt[c]];
		c=nxt[c];
	}
	del(uu,vv);
	while(cc!=uu)
	{
		//prin();
		e[vv].push_back({cc,mx});
		e[cc].push_back({vv,mx});
		//prin();
		dfs(1,0);
		d[c]=0;
		dfs(c,0);
		ans=min(ans,d[c]);
		del(vv,cc);
		//cout<<"ans:"<<d[c]<<endl<<endl;
		
		cc=nxt[cc];
	}
	cc=nxt[cc];
	while(nxt[cc]!=cc)
	{
		//prin();
		e[uu].push_back({cc,mx});
		e[cc].push_back({uu,mx});
		//prin();
		dfs(1,0);
		d[c]=0;
		dfs(c,0);
		ans=min(ans,d[c]);
		del(uu,cc);
		//cout<<"ans:"<<d[c]<<endl<<endl;
		cc=nxt[cc];
	}
	cout<<ans;
	return 0;
}
