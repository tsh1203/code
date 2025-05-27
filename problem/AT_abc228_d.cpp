#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=1<<20,q,a[1050000],fa[1050000];
int find(int x)//板子 
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	for(int i=1;i<=n;i++)fa[i]=i,a[i]=-1;
	cin>>q;
	while(q--)
	{
		int t,x,p;
		cin>>t>>x;
		p=find(x%n+1);
		if(t==1)
		{
			if(a[p]==-1) a[p]=x;
			if(p==n)fa[p]=1;
			else fa[p]=p+1;
		}
		else cout<<a[x%n+1]<<endl;
	}
	return 0;
}
