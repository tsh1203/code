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
int n,a,b,c;
int x[N],f[N],q[N];
long double K(int i){return 2.0*a*x[i];}
int X(int i){return x[i];}
int Y(int i){return f[i]+a*x[i]*x[i]-b*x[i];}
long double xl(int a,int b){
	return 1.0*(Y(a)-Y(b))/(X(a)-X(b));
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,a,b,c);
	for(int i=1;i<=n;i++)read(x[i]),x[i]+=x[i-1];
	int L=0,R=0;
	for(int i=1;i<=n;i++){
		while(L<R&&xl(q[L],q[L+1])>=K(i))L++;
		int j=q[L],d=x[i]-x[j];
		f[i]=f[j]+a*d*d+b*d+c;
		while(L<R&&xl(q[R-1],q[R])<=xl(q[R],i))R--;
		q[++R]=i;
	}
	cout<<f[n];
	return 0;
}