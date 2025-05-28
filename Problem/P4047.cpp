#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no
{
	int u,v;
	double w;
}a[1000006];
int n,f[10005],cnt,k,l;
int x[10005],y[10005];
void add(int u,int v,double w)
{
	a[++cnt].u=u;
	a[cnt].v=v;
	a[cnt].w=w;
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
bool cmp(no a,no b)
{
	return a.w<b.w;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			add(i,j,t);
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=find(a[i].u);
		int v=find(a[i].v);
		if(u==v)continue;
		f[u]=v;
		l++;
		if(l==n-k+1)
		{
			printf("%.2lf",a[i].w);
			return 0;
		}
	}
	return 0;
}
