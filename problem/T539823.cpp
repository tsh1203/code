#include<bits/stdc++.h>
using namespace std;
int n,f[100000];
int ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		int fl=1;
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]<=f[j])fl=0;
		}
		if(fl)ans++;
	}
	cout<<ans;
	return 0;
}
