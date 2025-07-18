#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int a[1<<21],fa[1<<21];
int ans=0;
int dfs(int d,int x){
	if(d==n)return a[x]=1;
	return a[x]=(dfs(d+1,x*2)+dfs(d+1,x*2+1))+1;
}
void pushup(int x,int sz){
	int t=x;
	while(t&&fa[t]){
		t=fa[t];
		a[t]-=sz;
	}
}
int cnt(int x){
	int f=x;
	while(fa[f]&&f!=1)f=fa[f];
	return a[f];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<(1<<(n-1));i++){
		fa[i]=i/2;
	}
	dfs(1,1);
	while(m--){
		int x,y;
		cin>>x>>y;
		if(x==1){
			if(fa[y]&&y!=1){
				pushup(y,a[y]);
				fa[y]=0;
			}
		}
		else{
			ans^=cnt(y);
		}
	}
	cout<<ans;
	return 0;
}
