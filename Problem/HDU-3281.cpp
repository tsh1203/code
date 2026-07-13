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
const int N=80,M=2e3+3;
int T,idd,n,m;
int f[N][M];
signed main(){
//	freopen("praph.in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(T);
	n=60,m=1500;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][0]=0;
	for(int i=1;i<=m;i++)f[1][i]=i;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
//			if(ceil(log2(j+1))<i)f[i][j]=ceil(log2(j+1));
//			else 
			for(int w=1;w<=j;w++){
				f[i][j]=min(f[i][j],max(f[i-1][w-1],f[i][j-w])+1);
			}
		}
	}
	while(T--){
		read(idd,n,m);
		if(n>50)n=50;
		write(idd,f[n][m]),endline();
	}
	return 0;
}
