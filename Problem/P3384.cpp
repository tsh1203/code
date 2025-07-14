#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+10 ;

struct Edge{
	int next,target;
}edge[MAXN<<1];

struct SegTree{
	int lazy,sum;
}tree[MAXN<<2];

int n,T,rt,mod,cost[MAXN];//输入 
int cnt,head[MAXN];//树 
int f[MAXN],dep[MAXN],sz[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];//树链剖分 

//-------------------------------输入----------------------------------
inline void add(int u,int v){
	edge[++cnt]=(Edge){head[u],v};
	head[u]=cnt;
}

void input(){
	scanf("%d%d%d%d",&n,&T,&rt,&mod);
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]),cost[i]%=mod;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
}

//------------------------------线段树-----------------------------------------
inline void Push_down(int root,int l,int r){
	int mid = l+r >> 1 , z = tree[root].lazy;
	tree[root<<1].sum =  ( tree[root<<1].sum + (mid-l+1)*z%mod )%mod;
	tree[root<<1|1].sum = ( tree[root<<1|1].sum + (r-mid)*z%mod )%mod;
	tree[root<<1].lazy = ( tree[root<<1].lazy + z )%mod;
	tree[root<<1|1].lazy = ( tree[root<<1|1].lazy + z )%mod;
	tree[root].lazy = 0;
}

inline void Push_up(int root){
	tree[root].sum=(tree[root<<1].sum+tree[root<<1|1].sum)%mod;
}

void Update(int root,int l,int r,int L,int R,int p){
	if( L<=l&&r<=R ){
		tree[root].lazy = ( tree[root].lazy + p )%mod;
		tree[root].sum = ( tree[root].sum + p*(r-l+1)%mod )%mod;
		return;
	}
	if( R<l||r<L ) return;
	Push_down(root,l,r);
	int mid = l+r >> 1 ;
	Update(root<<1,l,mid,L,R,p); Update(root<<1|1,mid+1,r,L,R,p);
	Push_up(root);
}

int Query(int root,int l,int r,int L,int R){
	if( L<=l&&r<=R ) return tree[root].sum;
	if( R<l || r<L ) return 0;
	Push_down(root,l,r);
	int sum = 0 , mid = l+r >> 1;
	sum = Query(root<<1,l,mid,L,R) + Query(root<<1|1,mid+1,r,L,R) ;
	Push_up(root);
	return sum%mod;
}

void build(int root,int l,int r){
	if(l==r){
		tree[root].sum=cost[rk[l]];
		return;
	}
	int mid = l+r >> 1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	Push_up(root);
}

//---------------------------------树剖-------------------------------------
void Urange(int a,int b,int z){
	z%=mod;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]]) swap(a,b);
		Update(1,1,n,id[top[b]],id[b],z);
		b=f[top[b]];
	}
	if(id[a]>id[b]) swap(a,b);
	Update(1,1,n,id[a],id[b],z);
}

int Qrange(int a,int b){
	int ans=0;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]]) swap(a,b);
		ans = ( ans + Query(1,1,n,id[top[b]],id[b]) )%mod;
		b=f[top[b]];
	}
	if(id[a]>id[b]) swap(a,b);
	ans = ( ans + Query(1,1,n,id[a],id[b]) )%mod;
	return ans;
}

void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	sz[u]=1;
	for(int i=head[u];i;i=edge[i].next)
		if(edge[i].target!=f[u]){
			int v=edge[i].target;
			f[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]]) son[u]=v;
		}
}

void dfs2(int u,int t){
	top[u]=t;
	id[u]=++cnt;
	rk[cnt]=u;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].target;
		if(v!=son[u]&&v!=f[u]) dfs2(v,v);
	}
}

void handle(){
	dfs1(rt);
	cnt=0;
	dfs2(rt,rt);
	build(1,1,n);
}
void solve(){
	for(int i=1;i<=T;i++){
		int opt,x,y,z;
		scanf("%d",&opt);
		switch (opt){
		case 1:
			scanf("%d%d%d",&x,&y,&z);
			Urange(x,y,z);
			break;
		case 2:
			scanf("%d%d",&x,&y);
			printf("%d\n",Qrange(x,y));
			break;
		case 3:
			scanf("%d%d",&x,&z);
			Update(1,1,n,id[x],id[x]+sz[x]-1,z%mod);
			break;
		case 4:
			scanf("%d",&x);
			printf("%d\n",Query(1,1,n,id[x],id[x]+sz[x]-1));
			break;
		}
	}
}

int main(){
	input();
	handle();
	solve();
	return 0;
}
