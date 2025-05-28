//给定一个有n个元素的整数数列 a[1],a[2],…,a[n]，你需要依次进行m个操作，操作有两类：
//1 i d：给定 i,d，将 a[i] 加上 d；
//0 l r：给定 l,r，求 a[l]+a[l+1]+⋯+a[r]的值。
#include <bits/stdc++.h>
using namespace std;
long long n,m,t[2000006];
long long lowbit(long long k)
{
	return k & -k;
}
void add(long long x,long long k)
{
	while(x<=n)
	{
		t[x]+=k;
		x+=lowbit(x);
	}
}
long long sum(long long x)
{
	long long ans=0;
	while(x!=0)
	{
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long a;
		scanf("%lld",&a);
		add(i,a);
	}
	for(int i=1;i<=m;i++)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==1)
			add(b,c);
		if(a==0)
			printf("%lld\n",sum(c)-sum(b-1));
	}
	return 0;
}
