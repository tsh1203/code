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
const int N=2e6+6;
int n,m,k;
int a[N],s[N],f[N],nxt[N];
int be[N],ed[N];
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	read(n);
	k=sqrt(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		s[i]=(i-1)/k+1;
	}
	for(int i=1;i<=n/k+1;i++){
		be[i]=(i-1)*k+1;
		ed[i]=min(n,i*k);
	}
	for(int i=n;i>0;i--){
		if(i+a[i]>ed[s[i]])f[i]=1,nxt[i]=i+a[i];
		else f[i]=f[i+a[i]]+1,nxt[i]=nxt[i+a[i]];
	}
	read(m);
	while(m--){
		int op,j,kk;
		read(op,j);
		j++;
		if(op==1){
			int cnt=0;
			while(j<=n){
				cnt+=f[j];
				j=nxt[j];
			}
			write(cnt),endline();
		}
		else{
			read(kk);
			a[j]=kk;
			int i=s[j];
			for(int j=ed[i];j>=be[i];j--){
				if(j+a[j]>ed[i])f[j]=1,nxt[j]=j+a[j];
				else f[j]=f[j+a[j]]+1,nxt[j]=nxt[j+a[j]];
			}
		}
	}
	return 0;
}
