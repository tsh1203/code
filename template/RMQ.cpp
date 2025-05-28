//输入一串数字，给你M个询问，每次询问就给你两个数字L和R，请求出L~R这一段中的最大值。
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200005];
int l,r;
ll f[100005][30];
void sb()
{
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	int k=log2(n);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	return;
}
ll sc(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sb();
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",sc(l,r));
	}
	return 0;
}
