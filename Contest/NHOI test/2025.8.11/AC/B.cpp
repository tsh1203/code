#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int N=5e4+5;
int n;
struct no{
	int v;
	int u,d;
};
no g[N];
int s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	read(n);
	for(int i=1;i<=n;i++)
		read(g[i].v,g[i].u,g[i].d);
	
	int res=0;
	for(int i=1;i<=n;i++)
		res+=g[i].d;
	
	int q;
	read(q);
	while(q--){
		int ini;
		read(ini);
		if(ini>res)
			write(ini-res),endline();
		else{
			for(int j=1;j<=n;j++)
				if(ini<=g[j].v) ini+=g[j].u;
			else{
				ini=ini-g[j].d;
				if(ini<0) ini=0; 
			} 
			write(ini),endline();
		}
	}
	return 0;
}
