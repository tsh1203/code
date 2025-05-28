#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,k,q,x,top; 
int w[400005],ww;
int f[200005];
int b[200005],an[200005];
int rp;
int findd(int x)
{
//	for(int i=1;i<=2*n;i++)
//	{
//		if(x<=w[i])return i;
//	}
	int l=1,r=2*n;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(x<w[mid])r=mid;
		else if(x==w[mid])return mid;
		else l=mid;
	}
	return r;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rp++;
	
	cin>>n>>q>>x;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i+n]=w[i];
	}
	for(int i=1;i<=2*n;i++)
	{
		w[i]+=w[i-1];
	}
	
	int qwq=w[n],now=1;
	
	for(int i=1;!f[now];i++)
	{
		top++;
		f[now]=i;
		int d=lower_bound(w,w+2*n+1,w[now-1]+x%qwq)-w;
		an[i]=(d-now+1)+x/qwq*n;
		now=d%n+1;
	}
	
	int len=top-f[now]+1;
	
	while(q--)
	{
		cin>>k;
		if(k>=f[now])
		{
			k=(k-f[now])%len+f[now];
		}
		cout<<an[k]<<endl;
	}
	return 0;
}
