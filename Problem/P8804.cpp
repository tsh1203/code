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
const int N=102,M=102;
struct no{int id;double p;};
int n,m,k,p[N],v[M];
double g[N][M];
no a[N];
bool cmp(no x,no y){
	if(abs(x.p-y.p)>1e-18)return x.p>y.p;
	return x.id<y.id;
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(p[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			read(x);
			g[i][j]=x/100.0;
		}
	}
	read(k);
	for(int i=1;i<=k;i++){
		int x;
		read(x);
		v[x]=1.0;
	}
	double s=0.0;
	for(int i=1;i<=n;i++){
		double cur=1.0;
		for(int j=1;j<=m;j++){
			if(v[j])cur*=g[i][j];
			else cur*=(1.0-g[i][j]);
		}
		a[i]={i,cur*p[i]};
		s+=a[i].p;
	}
	for(int i=1;i<=n;i++){
		
		if(s>1e-18)a[i].p=a[i].p/s*100.0;
		else a[i].p=0.0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%lld %.2f\n",a[i].id,a[i].p);
	}
	return 0;
}
