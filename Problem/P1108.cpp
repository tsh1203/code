#include<bits/stdc++.h>
using namespace std;
int n,ans=1,an;
int a[5003],f[5003],t[5003];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1;
		t[i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[i])
			{
				if(f[i]<f[j]+1)f[i]=f[j]+1,t[i]=t[j];
				else if(f[i]==f[j]+1)t[i]+=t[j];
			}
			if(a[j]==a[i])
			{
				f[j]=0;
				t[j]=0;
			}
		}
		ans=max(ans,f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==ans)an+=t[i];
	}
	cout<<ans<<" "<<an;
	return 0;
}
