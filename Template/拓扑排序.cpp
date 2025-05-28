#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int N = 100010;
int h[N],ne[N],e[N],idx;
int d[N],q[N];
int n,m;
void add(int a,int b)
{
	e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
bool topsort()
{
	int hh=0,tt=-1;
	for(int i=1;i<=n;i++)
	{
		if(!d[i]) q[++tt]=i;
	}
	while(hh<=tt)
	{
		int t=q[hh++];
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(--d[j]==0){
				q[++tt]=j;
			}
		}
	}
	return tt==n-1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(h,-1,sizeof(h));
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		d[b]++;
	}
	if(topsort())
	{
		for(int i=0;i<n;i++) cout<<q[i]<<" ";
	}
	else cout<<-1;
	return 0;
}

