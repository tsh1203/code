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
const int N=1e5+5,M=1e2+2;
int n,m,f[3][M],q[M],a[N],ans=-1e18;
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	memset(q,128,sizeof q);q[0]=0;
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=m;i++)f[0][i]=-1e18;
	for(int i=1;i<=n;i++){
		int t=q[0];
		memset(f[i&1],128,sizeof f[i&1]);
		for(int j=1;j<=min(i,m);j++){
			int x=q[j];
			f[i&1][j]=max(f[(i-1)&1][j],t)+a[i];
			q[j]=max(q[j],f[i&1][j]);
			t=x;
		}
	}
	cout<<q[m];
	return 0;
}
