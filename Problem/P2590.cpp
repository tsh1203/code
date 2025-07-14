#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=1e5+10;

struct Edge{int next,target;}edge[MAXN<<1];

struct SegTree{int lazy,sum,max;}tree[MAXN<<2];

int n,q;
int cost[MAXN];
int cnt,head[MAXN];
int f[MAXN],dep[MAXN],sz[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];

inline void add(int u,int v){
	edge[++cnt]=(Edge){head[u],v};
	head[u]=cnt;
}

void input(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	cin>>q;
}

inline void Push_down(int root,int l,int r){
	int mid=(l+r)>>1,z=tree[root].lazy;
	if(z){
		tree[root<<1].sum+=(mid-l+1)*z;
		tree[root<<1|1].sum+=(r-mid)*z;
		tree[root<<1].max+=z;
		tree[root<<1|1].max+=z;
		tree[root<<1].lazy+=z;
		tree[root<<1|1].lazy+=z;
		tree[root].lazy=0;
	}
}

inline void Push_up(int root){
	tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
	tree[root].max=max(tree[root<<1].max,tree[root<<1|1].max);
}

void Update(int root,int l,int r,int L,int R,int p){
	if(L<=l&&r<=R){
		tree[root].lazy+=p;
		tree[root].sum+=p*(r-l+1);
		tree[root].max+=p;
		return;
	}
	if(R<l||r<L)return;
	Push_down(root,l,r);
	int mid=(l+r)>>1;
	Update(root<<1,l,mid,L,R,p);
	Update(root<<1|1,mid+1,r,L,R,p);
	Push_up(root);
}

int QuerySum(int root,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tree[root].sum;
	if(R<l||r<L)return 0;
	Push_down(root,l,r);
	int mid=(l+r)>>1;
	return QuerySum(root<<1,l,mid,L,R)+QuerySum(root<<1|1,mid+1,r,L,R);
}

int QueryMax(int root,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tree[root].max;
	if(R<l||r<L)return -1e9;
	Push_down(root,l,r);
	int mid=(l+r)>>1;
	return max(QueryMax(root<<1,l,mid,L,R),QueryMax(root<<1|1,mid+1,r,L,R));
}

void build(int root,int l,int r){
	if(l==r){
		tree[root].sum=cost[rk[l]];
		tree[root].max=cost[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	Push_up(root);
}

void Urange(int a,int b,int z){
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])swap(a,b);
		Update(1,1,n,id[top[b]],id[b],z);
		b=f[top[b]];
	}
	if(id[a]>id[b])swap(a,b);
	Update(1,1,n,id[a],id[b],z);
}

int QrangeSum(int a,int b){
	int ans=0;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])swap(a,b);
		ans+=QuerySum(1,1,n,id[top[b]],id[b]);
		b=f[top[b]];
	}
	if(id[a]>id[b])swap(a,b);
	ans+=QuerySum(1,1,n,id[a],id[b]);
	return ans;
}

int QrangeMax(int a,int b){
	int ans=-1e9;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])swap(a,b);
		ans=max(ans,QueryMax(1,1,n,id[top[b]],id[b]));
		b=f[top[b]];
	}
	if(id[a]>id[b])swap(a,b);
	ans=max(ans,QueryMax(1,1,n,id[a],id[b]));
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
			if(sz[v]>sz[son[u]])son[u]=v;
		}
}

void dfs2(int u,int t){
	top[u]=t;
	id[u]=++cnt;
	rk[cnt]=u;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].target;
		if(v!=son[u]&&v!=f[u])dfs2(v,v);
	}
}

void handle(){
	dfs1(1);
	cnt=0;
	dfs2(1,1);
	build(1,1,n);
}

void solve(){
	for(int i=1;i<=q;i++){
		char op[10];
		int u,v,t;
		cin>>op;
		if(op[0]=='C'){
			cin>>u>>t;
			Urange(u,u,t-cost[u]);
			cost[u]=t;
		}else if(op[1]=='M'){
			cin>>u>>v;
			cout<<QrangeMax(u,v)<<"\n";
		}else{
			cin>>u>>v;
			cout<<QrangeSum(u,v)<<"\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	handle();
	solve();
	return 0;
}
