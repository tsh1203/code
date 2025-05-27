#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int f[10004],nex[10004],to[10004],tot;
int n,m;
int ans;
bool p[10004];
void find(int x)
{
	p[x]=true;
	ans++;
	for(int i=f[x];i;i=nex[i])
	{
		int y=to[i];
		if(p[y])continue;
		find(y);
	} 
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		tot++;
		nex[tot]=f[x];
		f[x]=tot;
		to[tot]=y;
	}
	for(int i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		find(i);
	} 
	cout<<ans;
	return 0;
}
