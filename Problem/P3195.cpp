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
const int N=50004;
int n,l,h,t;
int s[N],f[N],g[N],q[N],dp[N];
long double ws(int x,int y){return (long double)((dp[y]+g[y]-dp[x]-g[x])/(f[y]-f[x]));}
signed main(){
	read(n,l);
	dp[0]=f[0]=0;
	g[0]=(l+1)*(l+1);
	for(int i=1;i<=n;i++){
		read(s[i]);
		s[i]+=s[i-1],f[i]=s[i]+i;
		g[i]=(f[i]+l+1)*(f[i]+l+1);
	}
	for(int i=1;i<=n;i++){
		while(h<t&&ws(q[h],q[h+1])<=2.0*f[i])++h;
		dp[i]=dp[q[h]]+(f[i]-f[q[h]]-l-1.0)*(f[i]-f[q[h]]-l-1.0);
		while(h<t&&ws(q[t],i)<ws(q[t-1],q[t]))--t;
		q[++t]=i;
	}
	write(dp[n]);
	return 0;
}
