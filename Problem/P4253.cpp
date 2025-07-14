#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],b[N],d[N][(int)(log2(N)+5)];
int f[N][(int)log2(N)+5][2];
int ans=1e16,an;
int fa(int p,int q){
	if((1<<(q-1))>p)
		return -1;
	return p>>q;
}
int ls(int p){
	return 2*p;
}
int rs(int p){
	return 2*p+1; 
}
int br(int q,int p){
	return (q>>(p-1))^1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	m=log2(n)+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		cin>>b[i];
	d[1][1]=0;
	for(int i=2;i<=n;i++){
		d[i][1]=b[i];
		for(int j=1;j<=m;j++){
			if(fa(i,j)<0)continue;
			d[i][j]=d[fa(i,1)][j-1]+b[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(fa(i,j)<0)break;
			if(i*2>n){
				f[i][j][0]=d[i][j]*a[fa(i,j)];
				f[i][j][1]=a[br(i,j)]*d[i][j]+a[br(i,j)]*d[br(i,j)][1];
			}
			else if(i*2+1>n&&i*2<=n){
				f[i][j][0]=f[ls(i)][j+1][0]+d[ls(i)][1]*a[ls(i)];
				f[i][j][1]=f[ls(i)][j+1][1]+d[ls(i)][1]*a[ls(i)];
			} 
			else{
				f[i][j][0]=min(f[ls(i)][1][1]+f[rs(i)][j+1][0]+a[ls(i)]*d[ls(i)][1],f[rs(i)][1][1]+f[ls(i)][j+1][0]+a[rs(i)]*d[rs(i)][1]); 
				f[i][j][1]=min(f[ls(i)][1][1]+f[rs(i)][j+1][1]+a[ls(i)]*d[ls(i)][1],f[rs(i)][1][1]+f[ls(i)][j+1][1]+a[rs(i)]*d[rs(i)][1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		an=f[i][1][0];
		int now=i,j=fa(i,1);
		while(j>=1&&j<=n)
		{
			if(br(now,1)<=n)
				an+=d[br(now,1)][1]*a[br(now,1)]+f[br(now,1)][2][0];
			else 
				an+=d[j][1]*a[fa(j,1)];
			now=fa(now,1);
			j=fa(j,1);
		}
		ans=min(an,ans);
	}
	cout<<ans;
	return 0;
}
