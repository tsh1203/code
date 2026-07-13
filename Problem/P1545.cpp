#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
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
const int N=1e6+6;
int n,L,A,B;
int f[N],fl[N],tr[N<<2];
int ls(int x){return x<<1;}
int rs(int x){return (x<<1)|1;}
void pushup(int x){
	tr[x]=min(tr[ls(x)],tr[rs(x)]);
}
void build(int l,int r,int x){
	if(l==r){
		tr[x]=f[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	pushup(x);
}
void update(int nl,int nr,int l,int r,int x,int d){
	if(nl<=l&&r<=nr){
		tr[x]=d;
		return;
	}
	int mid=(l+r)>>1;
	if(nl<=mid)update(nl,nr,l,mid,ls(x),d);
	if(mid<nr)update(nl,nr,mid+1,r,rs(x),d);
	pushup(x); 
}
int query(int nl,int nr,int l,int r,int x){
	if(nl>nr)return 1e18;
	if(nl<=l&&r<=nr)return tr[x];
	int mid=(l+r)>>1,cnt=1e18;
	if(nl<=mid)cnt=min(cnt,query(nl,nr,l,mid,ls(x)));
	if(mid<nr)cnt=min(cnt,query(nl,nr,mid+1,r,rs(x)));
	return cnt;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,L,A,B);
	for(int i=1,s,e;i<=n;i++){
		read(s,e);
		fl[s+1]++,fl[e]--;
	}
	for(int i=1;i<=L;i++){
		fl[i]+=fl[i-1];
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	build(0,L,1);
	for(int i=1;i<=L;i++){
		if(fl[i]||i&1)continue;
		int l=i-2*B,r=i-2*A;
		if(l<0&&r<0)continue;
		l=max(l,0ll);
		f[i]=query(l,r,0,L,1)+1;
		update(i,i,0,L,1,f[i]);
	}
	if(f[L]<1e9)cout<<f[L];
	else cout<<-1;
	return 0;
}