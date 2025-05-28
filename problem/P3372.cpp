#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,c,m;
int k;
int a[300005],s[300005];
int ans[100005];
int ad[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(i-1)/k+1;
		ans[s[i]]+=a[i];
	}
	while(m--)
	{
		int c,l,r,z;
		cin>>c>>l>>r;
		if(c==1)
		{
			cin>>z;
			if(l>r)swap(l,r);
			for(int i=s[l]+1;i<s[r];i++)
			{
				ad[i]+=z;
			}
			for(int i=l;i<=min(r,s[l]*k);i++)
			{
				a[i]+=z;
			}
			if(s[l]!=s[r])
			{
				for(int i=r;i>=(s[r]-1)*k+1;i--)
				{
					a[i]+=z;
				}
			}
			ans[s[l]]+=z*(min(r,s[l]*k)-l+1);
			if (s[l]!=s[r]) 
				ans[s[r]]+=z*(r-((s[r]-1)*k+1)+1);
		}
		else
		{
			if(l>r)swap(l,r);
			int an=0;
			for(int i=s[l]+1;i<s[r];i++)
			{
				an+=ans[i]+ad[i]*k;
			}
			for(int i=l;i<=min(r,s[l]*k);i++)
			{
				an+=a[i]+ad[s[i]];
			}
			if(s[l]!=s[r])
			{
				for(int i=r;i>=(s[r]-1)*k+1;i--)
				{
					an+=a[i]+ad[s[i]];
				}
			}
			cout<<an<<endl;
		}
		
	}
	return 0;
}
