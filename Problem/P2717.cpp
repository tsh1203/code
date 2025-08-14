#include<bits/stdc++.h>
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
int n;
int mi=1e9,k,s[N];
int ans;
unordered_map<int,int>c;
int lb(int k)
{
	return k&-k;
}
void add(int x){
	while(x<=1e9+9){
		c[x]++;
		x+=lb(x);
	}
}
int ask(int x){
	int res=0;
	while(x){
		res+=c[x];
		x-=lb(x);
	}
	return res;
}
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++){
		read(s[i]);
		s[i]+=s[i-1]-k;
		mi=min(mi,s[i]);
		if(s[i]>=0)ans++;
	}
	for(int i=1;i<=n;i++){
		s[i]-=mi-1;
		ans+=ask(s[i]);
		add(s[i]);
	}
	write(ans);
	return 0;
}
