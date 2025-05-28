#include<bits/stdc++.h>
using namespace std;
long long n,t,a[10005],f[10005],ma=INT_MIN;
int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[0]=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=t+1; 
		while(r-l>1)
		{
			int m=l+(r-l)/2;
			if(f[m]<a[i]) l=m; 
			else r=m;
		}
		int x=l+1;
		if(x>=t) t=x; f[x]=a[i];
	}
	cout<<t;
	return 0;
}
