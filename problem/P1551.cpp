#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
int f[10000];
int n,m,k,x,y;
int find(int x)
{
	if(x==f[x])
		return x;
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		int f1,f2;
		f1=find(x);
		f2=find(y);
		f[f1]=f2;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		int f1,f2;
		f1=find(x);
		f2=find(y);
		if(f1==f2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
