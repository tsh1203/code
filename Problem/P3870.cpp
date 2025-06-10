#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k;
int s[100005];
int ans[1003];
bool ad[1003],a[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		s[i]=(i-1)/k+1;
	}
	while(m--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==0)
		{
			for(int i=s[x]+1;i<s[y];i++)
			{
				ad[i]=!ad[i];
			}
			for(int i=x;i<=min(y,s[x]*k);i++)
			{
				if(a[i])ans[s[i]]++;
				else ans[s[i]]--;
				a[i]=!a[i];
			}
			if(s[x]!=s[y])
			{
				for(int i=y;i>=(s[y]-1)*k+1;i--)
				{
					if(a[i])ans[s[i]]++;
					else ans[s[i]]--;
					a[i]=!a[i];
				}
			}
		}
		else
		{
			int an=0;
			for(int i=s[x]+1;i<s[y];i++)
			{
				if(ad[i])an+=k-ans[i];
				else an+=ans[i];
			}
			for(int i=x;i<=min(y,s[x]*k);i++)
			{
				an+=a[i]^ad[s[i]];
			}
			if(s[x]!=s[y])
			{
				for(int i=y;i>=(s[y]-1)*k+1;i--)
				{
					an+=a[i]^ad[s[i]];
				}
			}
			cout<<an<<endl;
		}
	}
	return 0;
}
