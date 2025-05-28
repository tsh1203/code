#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[1000001];
int a[1000001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=r&&x[l]+m<=i)l++;
		while(l<=r&&a[i]<a[x[r]])r--;
		r++;
		x[r]=i;
		if(i>=m)cout<<a[x[l]]<<" ";
	}
	cout<<endl;
	
	memset(x,0,sizeof(x));
	
	l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=r&&x[l]+m<=i)l++;
		while(l<=r&&a[i]>a[x[r]])r--;
		r++;
		x[r]=i;
		if(i>=m)cout<<a[x[l]]<<" ";
	}
	return 0;
}
