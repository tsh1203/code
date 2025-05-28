#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,q,ans;
int f[150004];
vector<int>v[150004];
bool b[150004];
void bfs(int x,int k)
{
	queue<int>q;
	ans=0;
	memset(b,0,sizeof(b));
	
	q.push(x);
	f[x]=0;
	b[x]=1;
	
	while(q.size())
	{
		int y=q.front();
		q.pop();
		if(f[y]>k)break;
		ans+=y;
		for(auto i:v[y])
		{
			if(!b[i])
			{
				q.push(i);
				b[i]=1;
				f[i]=f[y]+1;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>q;
	while(q--)
	{
		int x,k;
		cin>>x>>k;
		bfs(x,k);
		cout<<ans<<endl;
	}
	return 0;
}
