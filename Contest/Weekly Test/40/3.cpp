#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,q;
int cnt,ans[1000006],a[1000006];
bool b[1000006],f[1000006];
vector<pair<int,int>>e[1000006];
void build(int u)
{
    a[u]=cnt;
    b[u]=1;
    for(auto x:e[u])
	{
		int v=x.first,w=x.second;
        if(!b[v])
		{
			ans[v]=ans[u]+w;
			build(v);
		}
        else if(ans[v]!=ans[u]+w)
		{
			f[cnt]=1;
		}
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
	{
		int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,-w});
    }
    for(int i=1;i<=n;i++)
    	if(!b[i])
        {
          cnt++;
		build(i);
		}
    while(q--)
	{
		int u,v;
        cin>>u>>v;
        if(a[u]!=a[v])cout<<"nan"<<endl;
        else if(f[a[u]])cout<<"inf"<<endl;
        else cout<<ans[v]-ans[u]<<endl;
    }
    return 0;
}
