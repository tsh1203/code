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
#define x(i) b[i+1].w
#define k(i) -b[i].l
#define y(i) f[i]
using namespace FastIO;
const int N=5e4+4;
int n,mx,cnt;
int f[N];
struct no{int w,l;}a[N],b[N];
bool cmp(no a,no b){
	if(a.w!=b.w)return a.w>b.w;
	return a.l>b.l;
}
long double xl(int d1,int d2){
	return (y(d1)-y(d2)+0.0)/(x(d1)-x(d2)+0.0);
}
int q[N],L,R;
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].w,a[i].l);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].l>mx){
			b[++cnt]=a[i];
			mx=a[i].l;
		}
	}
	for(int i=1;i<=cnt;i++){
		while(L<R&&xl(q[L],q[L+1])>=k(i))L++;
		int j=q[L];
		f[i]=f[j]+b[i].l*b[j+1].w;
		while(L<R&&xl(q[R-1],q[R])<=xl(q[R],i))R--;
		q[++R]=i;
	}
	cout<<f[cnt];
	return 0;
	
}
/*

}
*/