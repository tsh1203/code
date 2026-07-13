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
const int N=3e5+5;
int n,s;
int t[N],c[N],q[N],f[N],l=1,r;
int ck(int x,int i){
	if((t[i]+s)*(c[q[x+1]]-c[q[x]])<f[q[x+1]]-f[q[x]])return 1;
	return 0;
}
int nm(int i,int l,int r){
	return l<r&&(f[i]-f[q[r]])*(c[q[r]]-c[q[r-1]])<=(f[q[r]]-f[q[r-1]])*(c[i]-c[q[r]]);
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,s);
	for(int i=1;i<=n;i++){
		read(t[i],c[i]);
		t[i]+=t[i-1],c[i]+=c[i-1];
	}
	int L=0,R=0;
	for(int i=1;i<=n;i++){
		int l=L,r=R;
		while(l<r){
			int mid=(l+r)>>1;
			if(ck(mid,i))r=mid;
			else l=mid+1;
		}
		int j=q[r];
		f[i]=f[j]+(c[i]-c[j])*t[i]+(c[n]-c[j])*s;
		while(nm(i,L,R))R--;
		q[++R]=i;
	}
	cout<<f[n];
	return 0;
}