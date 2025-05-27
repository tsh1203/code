#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],x,ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[x]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[x]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)ans++;
	}
	cout<<ans;
	return 0;
}
