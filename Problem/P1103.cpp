#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k;
int f[102][102];
pair<int,int>a[102];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(f,127,sizeof f);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second,f[i][1]=0;
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			for(int m=2;m<=min(i,n-k);m++)
				f[i][m]=min(f[i][m],f[j][m-1]+abs(a[i].second-a[j].second));
	int ans=1e18;
	for(int i=n-k;i<=n;i++)
		ans=min(ans,f[i][n-k]);
	cout<<ans;
	return 0;
}
