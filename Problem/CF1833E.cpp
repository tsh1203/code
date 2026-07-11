#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define pii pair<int,int>
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
const int N=2e5+5;
int T,n,a[N],f[N],b[N],cnt,tot;
map<pii,int>v;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa!=fb)f[fa]=fb,cnt--;
}
void solve(){
	read(n);cnt=n,tot=0;
	memset(b,0,sizeof b);
	v.clear();
	for(int i=1;i<=n;i++){
		read(a[i]),f[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(v[{i,a[i]}])continue;
		v[{i,a[i]}]=v[{a[i],i}]=1;
		b[i]++,b[a[i]]++;
		merge(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1)tot++;
	}
	write(min(cnt,cnt-(tot/2)+1),cnt),endline();
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(T);
	while(T--)solve();
	return 0;
}
