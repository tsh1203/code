#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no
{
	int p,l;
};
int n;
int s[100005];
int sb[100005],ml[100005];
no a[100005];
bool cmp(no a,no b)
{
	return a.p>b.p;
}
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].l;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--)
	{
		sb[i]=max(sb[i+1],2*a[i].l+a[i].p);
	}
	for(int i=1;i<=n;i++)
	{
		ml[i]=max(ml[i-1],a[i].l);
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i].p;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<max(s[i-1]+sb[i],s[i]+2*ml[i])<<endl;
	}
	return 0;
}
