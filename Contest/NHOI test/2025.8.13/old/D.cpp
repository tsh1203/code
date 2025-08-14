#include<bits/stdc++.h>
#pragma GCC optimize("3")
#define int long long
using namespace std;
const int N=2350;
struct edge{
	int v,nxt;
}e[2*N];
int head[N],cnt,fa[N];
int q,n;
int color[N];
int r,dn,dfn[500005],mi[19][500005];
void add(int a,int b){
	e[++cnt]={b,head[a]};
	head[a]=cnt;
}
int get(int x,int y)
{
	if(dfn[x]<dfn[y])return x;
	return y;
}
void dfs(int u,int f)
{
	mi[0][dfn[u]=++dn]=f;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v!=f)dfs(v,u); 
	}
}
int lca(int u, int v)
{
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))swap(u,v);
	int d=__lg(v-u++);
	return get(mi[d][u],mi[d][v-(1<<d)+1]);
}
void dfs2(int f,int u){
	fa[u]=f;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v!=f)dfs2(u,v); 
	}
}
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>color[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=__lg(n);i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mi[i][j]=get(mi[i-1][j],mi[i-1][j+(1<<i-1)]);
		}
	}
	dfs2(0,1);
	while(q--){
		char op;
		int a,b,c;
		cin>>op>>a>>b;
		if(op=='C'){
			cin>>c;
			int l=lca(a,b);
			int u=a;
			while(u!=l){
				color[u]=c;
				u=fa[u];
				if(u==0)break;
			}
			u=b;
			while(u!=l){
				color[u]=c;
				u=fa[u];
				if(u==0)break;
			}
			color[l]=c;
		}
		else{
			int ans=0,la=0,lb=0;
			int l=lca(a,b);
			int u=a;
			while(u!=l){
				if(color[u]!=color[la])ans++;
				la=u;
				u=fa[u];
				if(u==0)break;
			}
			u=b;
			while(u!=l){
				if(color[u]!=color[lb])ans++;
				lb=u;
				u=fa[u];
				if(u==0)break;
			}
			ans++;
			if(color[la]==color[l])ans--;
			if(color[lb]==color[l])ans--;
			cout<<ans;
		}
	}
	return 0;
}
