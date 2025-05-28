#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,q;
int tot,cnt;
int f[1000006],a[1000006];
int box[1000006],ans[1000006];//现在的，原来的
int findd(int x)
{
	if(f[x]==x)return x;
	return f[x]=findd(f[x]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	tot=n;
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		a[i]=i;
		box[i]=i;
		ans[i]=i;
	}
	while(q--)
	{
		int op,x,y;
		cin>>op>>x;
		if(op==1)
		{
			cin>>y;
			f[box[y]]=f[box[x]];
			box[y]=++tot;
			f[tot]=tot;
			ans[tot]=y;
		}
		else if(op==2)
		{
			a[++cnt]=box[x];
		}
		else
		{
			cout<<ans[findd(a[x])]<<endl;
		}
	}
	return 0;
}
