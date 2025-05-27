#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int f[1000005],b[700004],a[700004];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
		{
			if(f[j-a[i]]+b[i]>f[j])
				f[j]=f[j-a[i]]+b[i];
		}
	}
	cout<<f[m];
	return 0;
}
