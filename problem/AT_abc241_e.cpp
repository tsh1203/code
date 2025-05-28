#include<bits/stdc++.h>
#pragma GCC optimize("3","inline","Ofast")
#define int long long
#define endl "\n"
using namespace std;
int a[200005],b[200005],x[200005];
int ans,st;
signed main()
{
	memset(b,-1,sizeof(b));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	while(st<k)
	{
		int r=ans%n;
		if(b[r]==-1)
		{
			b[r]=st;
			x[r]=ans;
			ans+=a[r];
			st++;
		}
		else
		{
			int t1=st-b[r],t2=k-st;
			int cnt=t2/t1;
			if(cnt>0)
			{
				ans+=cnt*(ans-x[r]);
				st+=cnt*t1;
				t2=k-st;
			}
			if(!t2)break;
			memset(b,-1,sizeof(b));//万万记得初始化
		}
	}
	cout<<ans;
	return 0;
}
