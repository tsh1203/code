#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=99999997;
int n,a[100005],b[100005],ans=0;
struct no
{
	int num,id;
}c[100005],d[100005];
bool cmp(no a,no b)
{
	return a.num<b.num;
}
void fun(int l,int mid,int r)
{
	int t1=l,t2=mid+1;
	for(int i=l;i<=r;i++)
	{
		if(t1<=mid&&a[t1]<=a[t2]||t2>r)b[i]=a[t1],t1++;
		else b[i]=a[t2],t2++,ans+=mid-t1+1;
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
}
void msort(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	fun(l,mid,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	msort(1,n);
	cout<<ans;
	return 0;
}
