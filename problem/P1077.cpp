#include<bits/stdc++.h>
using namespace std;
const int maxn=105,mod=1000007;
int n,m,a[maxn];
int f[1000][1000];
int dfs(int x,int k)
{
	if(f[x][k]>-10000000)return f[x][k];
	if(k>m)
	{
		f[x][k]=0;
		return 0;
	}
	if(k==m)
	{
		f[x][k]=1;
		return 1;
	}
	if(x==n+1)
	{
		f[x][k]=0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<=a[x];i++)ans=(ans+dfs(x+1, k+i))%mod;
	f[x][k]=ans;
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(f,128,sizeof(f));
	cout<<dfs(1,0)<<endl;
	return 0;
}
