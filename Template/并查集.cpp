#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int f[200005];
int find(int x)
{
	if (f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if (op==1)
		{
			int r1=find(x),r2=find(y);
			f[r2]=r1;
		}
		else
		{
			int r1=find(x),r2=find(y);
			if (r1==r2)cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}
