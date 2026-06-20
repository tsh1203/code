#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,now=1,cnt,a[N],lst[N],lstt[N],nxt[N],f[N],ans[N];
int main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		nxt[lst[a[i]]]=i,lst[a[i]]=i;
	}
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>now) break;
		for(int j=now+1;j<=nxt[i];j++)
		{
			f[j]=f[i]+1;
			lstt[j]=i;
		}
		now=max(now,nxt[i]); 
	}
	for(int i=n;i;i=lstt[i]) ans[cnt++]=i;
	cout<<cnt-1<<'\n';
	for(int i=cnt-1;i>=1;i--) cout<<ans[i]<<' ';
	return 0;
}
