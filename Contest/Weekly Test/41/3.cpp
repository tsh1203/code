#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no
{
	int x,y,z;
}e[2000006];
int n,m,cnt;
int f[100005],a[100005];
int res;
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int mi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2)ans*=a,ans%=m;
		a=a*a%m;
		b/=2;
	}
	return ans;
}
bool cmp(no a,no b)
{
	return a.z>b.z;
}
void kruskal()
{
	for(int i=1;i<=cnt;i++)
	{
		int ra=find(e[i].x);
		int rb=find(e[i].y);
		if(ra==rb)continue;
		res+=e[i].z;
		f[ra]=rb;
	}
} 
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[++cnt]={i,j,(int)(mi(a[i],a[j])+mi(a[j],a[i]))%m}; 
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
	cout<<res;
	return 0;
}
