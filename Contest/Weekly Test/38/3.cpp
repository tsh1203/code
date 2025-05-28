#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[200005],sum[200005],ans[200005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
        s[1]=max(s[1],a-1);
		s[a+1]=max(s[a+1],b-a-1);
		s[b+1]=max(s[b+1],m-b);
	}
	for(int i=1;i<=m;i++)
	{
		s[i+1]=max(s[i+1],s[i]-1);
		sum[s[i]]++;
	}
	int tot=0;
	for(int i=m;i>=1;i--)
	{
		tot+=sum[i];
		ans[i]=m-i+1-tot;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
