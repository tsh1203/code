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
		if(a==2)
			printf("%lld\n",sum(c)-sum(b-1));
	}
	return 0;
}
}
