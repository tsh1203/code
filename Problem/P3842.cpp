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
const int N=2e4+4;
int n;
int l[N],r[N],f[N][2];//左，右
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(l[i],r[i]);
	memset(f,127,sizeof f);
	f[1][0]=r[1]-1+r[1]-l[1],f[1][1]=r[1]-1;
	for(int i=2;i<=n;i++){
		f[i][1]=r[i]-l[i]+min(f[i-1][0]+abs(l[i]-l[i-1]),f[i-1][1]+abs(l[i]-r[i-1]))+1;
		f[i][0]=r[i]-l[i]+min(f[i-1][0]+abs(r[i]-l[i-1]),f[i-1][1]+abs(r[i]-r[i-1]))+1;
	}
	cout<<min(f[n][0]+n-l[n],f[n][1]+n-r[n]);
	return 0;
}
