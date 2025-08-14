#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
namespace FastIO {
	void read(){}
	template <class T1,class ... T2> inline void read(T1 &x,T2 &... oth){
		bool pd=0;x=0;char ch=getchar();
		while(!isdigit(ch)){pd|=ch=='-';ch=getchar();}
		while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		x=pd?-x:x;
		read(oth...);
	}
	template <class T> void _write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9) _write(x/10);
		putchar(x%10^48);
	}
	void write(){}
	template <class T1,class ... T2>
	inline void write(T1 x,T2 ...oth){_write(x);putchar(' ');write(oth...);}
	inline void endline(){putchar('\n');}
}//Orz lby 
using namespace FastIO;
using namespace std;
const int MAXN=1e5+10;
struct Edge{
	int next,target;
};
Edge edge[MAXN<<1];
struct SegTree{
	int lazy;
	int sum;
	int lc,rc;
};
SegTree tree[MAXN<<2];
int n,m;
int cnt,head[MAXN];
int f[MAXN],dep[MAXN],sz[MAXN],son[MAXN],rk[MAXN],id[MAXN],top[MAXN];
int w[MAXN];
int ans[MAXN],cntt;
void add(int u,int v){
	edge[++cnt]=(Edge){head[u],v};
	head[u]=cnt;
}
/////////这里下面格式自己改（包括变量名啥的） 
inline void pushdown(int rt){
	if(tree[rt].lazy){
		tree[rt<<1].lazy=tree[rt<<1|1].lazy=tree[rt].lazy;
		tree[rt<<1].lc=tree[rt<<1].rc=tree[rt].lazy;
		tree[rt<<1|1].lc=tree[rt<<1|1].rc=tree[rt].lazy;
		tree[rt<<1].sum=tree[rt<<1|1].sum=1;
		tree[rt].lazy=0;
	}
}
///////////////// 
void Push_up(int root){
	tree[root].lc=tree[root<<1].lc;
	tree[root].rc=tree[root<<1|1].rc;
	tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
	if(tree[root<<1].rc==tree[root<<1|1].lc)tree[root].sum--;
}
void build(int root,int l,int r){
	if(l==r){
		tree[root].sum=1;
		tree[root].lc=tree[root].rc=w[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	Push_up(root);
}
void Update(int root,int l,int r,int L,int R,int c){
	if(L<=l&&r<=R){
		tree[root].lazy=c;
		tree[root].sum=1;
		tree[root].lc=tree[root].rc=c;
		return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if(L<=mid)Update(root<<1,l,mid,L,R,c);
	if(R>mid)Update(root<<1|1,mid+1,r,L,R,c);
	Push_up(root);
}
SegTree Query(int root,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tree[root];
	pushdown(root);
	int mid=(l+r)>>1;
	if(R<=mid)return Query(root<<1,l,mid,L,R);
	if(L>mid)return Query(root<<1|1,mid+1,r,L,R);
	SegTree left=Query(root<<1,l,mid,L,R);
	SegTree right=Query(root<<1|1,mid+1,r,L,R);
	SegTree res;
	///////////神经哈，存都没存就减掉 
	res.lc=left.lc;
	res.rc=right.rc;
	res.sum=left.sum+right.sum;
	if(left.rc==right.lc)res.sum--;
	return res;
}
void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	sz[u]=1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].target;
		if(v!=f[u]){
			f[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])son[u]=v;
		}
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
void Urange(int a,int b,int c){
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])swap(a,b);
		Update(1,1,n,id[top[b]],id[b],c);
		b=f[top[b]];
	}
	if(id[a]>id[b])swap(a,b);
	Update(1,1,n,id[a],id[b],c);
}
/////////这里下面格式自己改 
int Qrange(int u,int v){
	SegTree resu,resv,tmp;
	resu.sum=resv.sum=-1;
	
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			tmp=Query(1,1,n,id[top[u]],id[u]);
			if(resu.sum==-1) resu=tmp;
			else{
				if(tmp.rc==resu.lc) resu.sum+=tmp.sum-1;
				else resu.sum+=tmp.sum;
				resu.lc=tmp.lc;
			}
			u=f[top[u]];
		}
		else{
			tmp=Query(1,1,n,id[top[v]],id[v]);
			if(resv.sum==-1) resv=tmp;
			else{
				if(tmp.rc==resv.lc) resv.sum+=tmp.sum-1;
				else resv.sum+=tmp.sum;
				resv.lc=tmp.lc;
			}
			v=f[top[v]];
		}
	}
	
	if(dep[u]>dep[v]){
		tmp=Query(1,1,n,id[v],id[u]);
		if(resu.sum==-1) resu=tmp;
		else{
			if(tmp.rc==resu.lc) resu.sum+=tmp.sum-1;
			else resu.sum+=tmp.sum;
			resu.lc=tmp.lc;
		}
	}
	else{
		tmp=Query(1,1,n,id[u],id[v]);
		if(resv.sum==-1) resv=tmp;
		else{
			if(tmp.rc==resv.lc) resv.sum+=tmp.sum-1;
			else resv.sum+=tmp.sum;
			resv.lc=tmp.lc;
		}
	}
	
	if(resv.sum==-1) return resu.sum;
	if(resu.sum==-1) return resv.sum;
	int ans=resu.sum+resv.sum;
	if(resu.lc==resv.lc) ans--;
	return ans;
}
//////////////////// 
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		read(w[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		read(u,v);
		add(u,v);
		add(v,u);
	}
	cnt=0;/////其实没用，你定的是全局 
	dfs1(1);
	cnt=0;////////问号？？？？？你以为是dfs序啊 
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		char op;
		cin>>op;
		if(op=='C'){
			int a,b,c;
			read(a,b,c);
			Urange(a,b,c);
		}else{
			int a,b;
			read(a,b);
			cout<<Qrange(a,b)<<"\n";
		}
	}
	return 0;
}
