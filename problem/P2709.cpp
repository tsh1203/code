#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no
{
	int l,r,id;
}f[50004];
int n,m,k;
int a[50004];
int kk,c[50004],ans[50004];
bool cmp(no a,no b)
{
	if(a.l/kk!=b.l/kk)return a.l<b.l;
	return a.r<b.r;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	kk=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>f[i].l>>f[i].r;
		f[i].id=i;
	}
	sort(f+1,f+m+1,cmp);
	int l=1,r=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		while(l>f[i].l)
		{
			l--;
			sum-=c[a[l]]*c[a[l]];
			c[a[l]]++;
			sum+=c[a[l]]*c[a[l]];
		}
		while(l<f[i].l)
		{
			sum-=c[a[l]]*c[a[l]];
			c[a[l]]--;
			sum+=c[a[l]]*c[a[l]];
			l++;
		}
		while(r<f[i].r)
		{
			r++;
			sum-=c[a[r]]*c[a[r]];
			c[a[r]]++;
			sum+=c[a[r]]*c[a[r]];
		}
		while(r>f[i].r)
		{
			sum-=c[a[r]]*c[a[r]];
			c[a[r]]--;
			sum+=c[a[r]]*c[a[r]];
			r--;
		}
		ans[f[i].id]=sum;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
