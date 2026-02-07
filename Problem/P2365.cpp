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
	template <class st> void _write(st x){
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
int n,s;
int t[N],f[N],st[N],sf[N],dp[N];
signed main(){
	read(n,s);
	memset(dp,127,sizeof dp);
	for(int i=1;i<=n;i++){
		read(t[i],f[i]);
		st[i]=st[i-1]+t[i];
		sf[i]=sf[i-1]+f[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+st[i]*(sf[i]-sf[j])+s*(sf[n]-sf[j]));
		}
	}
	write(dp[n]);
	return 0;
}
