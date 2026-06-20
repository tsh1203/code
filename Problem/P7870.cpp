#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define len(a) (st[a].r-st[a].l+1)
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
const int N=5e5+5;
int n,op,l,r,k,cnt;
struct no{int l,r;}st[N];
int sum(int l,int r){
	if(l>r)swap(l,r);
	return (l+r)*(r-l+1)/2;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(op);
		if(op==1){
			read(l,r);
			st[++cnt]={l,r};
		}
		else{
			read(k);
			int ans=0;
			while(k&&cnt){
				if(len(cnt)<=k)k-=len(cnt),ans+=sum(st[cnt].l,st[cnt].r),cnt--;
				else ans+=sum(st[cnt].r-k+1,st[cnt].r),st[cnt].r=st[cnt].r-k,k=0;
			}
			write(ans),endline();
		}
		
	}
	return 0;
}
