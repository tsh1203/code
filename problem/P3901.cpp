#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int a[100005],cnt[100005],ans[100005];
int k,an;
struct no
{
	int l,r,idx,id;
}f[100005];
bool cmp(no a,no b)
{
	if(a.id!=b.id)
		return a.id<b.id; 
	return (a.id&1)?(a.r<b.r):(a.r>b.r);
}
void add(int x)
{
	cnt[a[x]]++;
	if(cnt[a[x]]==2)
		an++;
}
void remove(int x)
{
	cnt[a[x]]--;
	if(cnt[a[x]]==1)
		an--;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		f[i]={l,r,i,l/k};
	}
	sort(f+1,f+m+1,cmp);
	int ll=1,rr=0;
	for(int i=1;i<=m;++i)
	{
		int l=f[i].l;
		int r=f[i].r;
		int idx=f[i].idx;
		while(ll>l)
		{
			ll--;
			add(ll);
		}
		while(rr<r)
		{
			rr++;
			add(rr);
		}
		while(ll<l)
		{
			remove(ll);
			ll++;
		}
		while(rr>r)
		{
			remove(rr);
			rr--;
		}
		if(an==0)ans[idx]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i])cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
