#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,to=1;
int ans;
int a[400005];
int su,la[400005],sum[400005],fst[400005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i]+m;
		su+=a[i];
	}
	sort(a+1,a+2*n+1);
	la[1]=a[1];
	sum[1]+=a[1];
	fst[1]=1;
	for(int i=2;i<=2*n;i++)
	{
		if((a[i]==la[to]||a[i]==la[to]+1)&&i<fst[to]+n)
		{
			la[to]=a[i];
			sum[to]+=a[i]%m;
		}
		else
		{
			ans=max(ans,sum[to]);
			to++;
			la[to]=a[i];
			sum[to]+=a[i]%m;
			fst[to]=i;
		}
	}
	ans=max(ans,sum[to]);
	cout<<max((int)0,su-ans);
	return 0;
}
