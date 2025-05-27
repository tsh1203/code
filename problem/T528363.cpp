#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000],b[10000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		for(int i=y+1;i<=z-1;i++)
		{
			a[i]=1;
			b[i]=1;
		}
		b[y]=1;
		if(x==2)a[y]=1,a[z]=1;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)sum++;
	}
	cout<<sum<<" ";
	sum=0;
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]==0)sum++;
	}
	cout<<sum;
	return 0;
}
