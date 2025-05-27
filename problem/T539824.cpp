#include<bits/stdc++.h>
using namespace std;
int n,f[100000],m;
int ans;
int x[10];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)cin>>f[j];
		sort(f+1,f+6);
		int ma=-1,id=0;
		for(int j=1;j<=5;j++)
		{
			if(f[j]>ma&&f[j]<=m)ma=f[j],id=j;
		}
		if(id==0)continue;
		x[ma]++;
		m-=ma;
	}
	for(int i=1;i<=5;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl<<m;
	return 0;
}
