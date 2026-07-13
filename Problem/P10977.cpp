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
const int N=1e5+5;
int n,m;
int a[N],q[N],f[N];
int l=1,r,s;
multiset<int>st;
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]>m){
			cout<<-1;
			return 0;
		}
	}
	for(int i=1,j=1;i<=n;i++){
		s+=a[i];
		while(s>m){
			s-=a[j++];
		}
		while(l<=r&&q[l]<j){
			if(l<r)st.erase(f[q[l]]+a[q[l+1]]);
			l++;
		}
		while(l<=r&&a[q[r]]<=a[i]){
			if(l<r)st.erase(f[q[r-1]]+a[q[r]]);
			r--;
		}
		q[++r]=i;
		if(l<r)st.insert(f[q[r-1]]+a[q[r]]);
		f[i]=f[j-1]+a[q[l]];
		if(st.size())f[i]=min(f[i],*st.begin());
	}
	cout<<f[n];
	return 0;
}