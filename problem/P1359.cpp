#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct no
{
	int from,to,next,l;
}; 
no a[1100000];
int k=0,p[2005],s,t,d[2005];
bool f[2005];
void add(int u,int v,int l)
{
	k++;
	a[k].from=u;
	a[k].to=v;
	a[k].l=l;
	a[k].next=p[u];
	p[u]=k;
} 
void dij()
{
	memset(d,127,sizeof(d));
	d[s]=0;
	for(int i=1;i<=n;i++)
	{
		int mi=-1;
		for(int j=1;j<=n;j++)
		{
			if(!f[j]&&(mi==-1||d[j]<d[mi]))
			{
				mi=j;
			}
		}
		f[mi]=true;
		for(int j=p[mi];j!=0;j=a[j].next)
		{
			int to=a[j].to;
			if(!f[to]&&d[mi]+a[j].l<d[to])
			{
				d[to]=d[mi]+a[j].l;
			}
		}
	}
}
signed main()
{
	cin>>n;
	int l;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>l;
			add(i,j,l); 
		}
	} 
	s=1,t=n;
	dij();
	if(d[t]<=1e10)cout<<d[t];
	else cout<<-1;
	return 0;
}
