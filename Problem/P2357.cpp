#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,f,a[200005],ad[2003];
int k,s[200005],ans[200005];
void add(int l,int r,int kk)
{
	if(l>r)swap(l,r);
	for(int i=s[l]+1;i<s[r];i++)
	{
		ad[i]+=kk;
	}
	for(int i=l;i<=min(r,s[l]*k);i++)
	{
		a[i]+=kk;
		ans[s[i]]+=kk;
	}
	if(s[l]!=s[r])
	{
		for(int i=r;i>=(s[r]-1)*k+1;i--)
		{
			a[i]+=kk;
			ans[s[i]]+=kk;
		}
	}
}
int cnt(int l,int r)
{
	int an=0;
	if(l>r)swap(l,r);
	for(int i=s[l]+1;i<s[r];i++)
	{
		an+=ans[i]+ad[i]*k;
	}
	for(int i=l;i<=min(r,s[l]*k);i++)
	{
		an+=a[i]+ad[s[i]];
	}
	if(s[l]!=s[r])
	{
		for(int i=r;i>=(s[r]-1)*k+1;i--)
		{
			an+=a[i]+ad[s[i]];
		}
	}
	return an;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>f;
	k=sqrt(n); 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(i-1)/k+1;
		ans[s[i]]+=a[i];
	}
	while(f--)
	{
		int op,x,y,z;
		cin>>op;
		if(op==1){
			cin>>x>>y>>z;
			add(x,y,z);
		} 
		if(op==2){
			cin>>x;
			add(1,1,x);
		}
		if(op==3){
			cin>>x;
			add(1,1,-x);
		}
		if(op==4){
			cin>>x>>y;
			cout<<cnt(x,y)<<endl;
		}
		if(op==5){
			cout<<a[1]+ad[1]<<endl;
		}
//		for(int i=1;i<=n;i++)cout<<a[i]+ad[s[i]]<<" ";
//		cout<<endl;
	}
	return 0;
} 
