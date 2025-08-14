//区间第k大
#include<bits/stdc++.h>
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

const int N=2e5+5;
int n,m,cnt;
int ans[N],tr[N]; 
struct no{
	int x,y,k,id,type;
}b[N<<1],b1[N<<1],b2[N<<1];
void add(int x,int y){
	while(x<=n){
		tr[x]+=y;
		x+=x&(-x);
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=tr[x];
		x-=x&(-x);
	}
	return ans;
}
void solve(int bl,int br,int l,int r){
	if(bl>br)
		return;
	if(l==r){
		for(int i=bl;i<=br;i++)
			if(b[i].type==2) ans[b[i].id]=l;
		return;
	}
	int mid=(l+r)>>1;
	int p1=0,p2=0;
	for(int i=bl;i<=br;i++){
		if(b[i].type==1){
			if(b[i].x<=mid){
				add(b[i].id,1ll);
				b1[++p1]=b[i];
			}
			else b2[++p2]=b[i];
		}
		else {
			int res=sum(b[i].y)-sum(b[i].x-1);
			if(res>=b[i].k) b1[++p1]=b[i];
			else {
				b[i].k-=res;
				b2[++p2]=b[i];
			}
		}
	}
	for(int i=1;i<=p1;i++)
		if(b1[i].type==1)
			add(b1[i].id,-1);
	for(int i=1;i<=p1;i++)
		b[i+bl-1]=b1[i];
	for(int i=1;i<=p2;i++)
		b[i+bl+p1-1]=b2[i];
	solve(bl,bl+p1-1,l,mid);
	solve(bl+p1,br,mid+1,r);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
	{
		int x;
		read(x);
		b[++cnt]={x,1,(int)(1e12),i,1ll};
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,k;
		read(x,y,k);
		b[++cnt]={x,y,k,i,2};
	}
	solve(1ll,cnt,-1e12,1e12);
	for(int i=1;i<=m;i++)
		write(ans[i]),endline();
	return 0;
}
