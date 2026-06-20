#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int __int128
//#ifdef __linux__
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
//#else
//#define getchar _getchar_nolock
//#define putchar _putchar_nolock
//#endif
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
const int N=1e5+5;
int n,a[N],r[N];
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y),t=x;
	x=y,y=t-a/b*y;
	return r;
}
int crt(){
	int nn=1,ans=0;
	for(int i=1;i<=n;i++)nn=nn*r[i];
	for(int i=1;i<=n;i++){
		int m=nn/r[i],x=0,y=0;
		exgcd(m,r[i],x,y);
		ans=(ans+a[i]*m*x%nn)%nn;
	}
	return(ans%nn+nn)%nn;
}

signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++)read(r[i],a[i]);
	write(crt());
	return 0;
}
