#include<bits/stdc++.h>
using namespace std;
long long a[1000005],ans,q,v,x,y; 
long long n,m;
int main()
{
	cin>>n>>q>>v;
	for (int i=1;i<=n;i++)
		cin>>a[i],ans+=a[i]>=v;
	while(q--)
	{
		cin>>x>>y;
		ans+=a[x]<v&&y>=v;
		ans-=a[x]>=v&&y<v;
		a[x]=y;
	}
	cout<<ans;
	return 0;
} 
