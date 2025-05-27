#include <bits/stdc++.h>
using namespace std;
int n,a[1003],b[1003],f[1003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(b[n]<0) 
	{
		cout<<"Impossible";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=0) 
		{
			for(int j=0;j<i;j++)
			{
				if(b[i]-b[j]>=0)
				{
					f[i]=max(f[j]+1,f[i]);
				}
			}
		}
	}
	
	cout<<f[n];
	return 0;
}
