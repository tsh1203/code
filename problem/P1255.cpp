#include<bits/stdc++.h>
using namespace std;
int n,ns=1; 
int a[5010],b[5010],c[5010];
void f()
{
	a[1]=1,b[1]=2;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=ns;j++)c[j]=a[j]+b[j];
		for(int j=1;j<=ns;j++)
		{
			if(c[j]>9)
			{
				c[j+1]+=c[j]/10;
				c[j]%=10;
				if(j+1>ns)ns++;
			}
		}
		for(int j=1;j<=ns;j++)a[j]=b[j];
		for(int j=1;j<=ns;j++)b[j]=c[j];
	}
}
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	if(n<3)
	{
		cout<<n;
		return 0;
	}
	f();
	for(int i=ns;i>0;i--)cout<<b[i];
	return 0;
}
