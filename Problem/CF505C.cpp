#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
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
const int N=6e4+5;
int n,d,m;
int p[N],a[N],f[N][502],mx;
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,d);
	for(int i=1;i<=n;i++)read(p[i]),a[p[i]]++,m=max(m,p[i]);
	for(int i=0;i<=m;i++){
		for(int k=0;k<=500;k++){
			f[i][k]=-1;
		}
	}
	mx=f[d][250]=a[d];
	for(int i=d;i<=m;i++){
		for(int k=0;k<=500;k++){
			int j=k-250+d;
			if(j<=0)continue;
			if(f[i][k]==-1)continue;
			if(i+j<=m){
				f[i+j][k]=max(f[i+j][k],f[i][k]+a[i+j]);
				mx=max(mx,f[i+j][k]);
			}
			if(i+j+1<=m){
				f[i+j+1][k+1]=max(f[i+j+1][k+1],f[i][k]+a[i+j+1]);
				mx=max(mx,f[i+j+1][k+1]);
			}
			if(i+j-1<=m&&j-1>0){
				f[i+j-1][k-1]=max(f[i+j-1][k-1],f[i][k]+a[i+j-1]);
				mx=max(mx,f[i+j-1][k-1]);
			}
		}
	}
	cout<<mx;
	return 0;
}
