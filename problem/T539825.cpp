#include<bits/stdc++.h>
using namespace std;
int n,f[100000],m;
int ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		string s;
		int x,y,z;
		cin>>s>>x>>y;
		if(s=="water")
		{
			for(int i=x;i<=y;i++)f[i]++;
		}
		else
		{
			ans=0;
			cin>>z;
			for(int i=x;i<=y;i++)if(f[i]>=z)f[i]=0,ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}
