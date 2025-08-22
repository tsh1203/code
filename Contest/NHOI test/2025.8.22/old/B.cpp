#include<bits/stdc++.h>
#define int long long
#define endl "\n"
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
const int mod=1e9+7;
int n,m;
int fr[N],nxt[N];
int b[N],cnt,ans;
int f[N];
int find(int x){
	if (f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		read(x,y);
		if(nxt[x]==y&&fr[y]==x)continue;
		int fa1=find(x),fa2=find(y);
		if(nxt[x]||fr[y]||fa1==fa2){
			cout<<0;
			return 0;
		}
		f[fa2]=fa1;
		fr[y]=x,nxt[x]=y;
	}
	for(int i=1;i<=n;i++){
		int fa=find(i);
		if(!b[fa]){
			cnt++;
			b[fa]=1;
		}
	}
	ans=1;
	for(int i=1;i<=cnt;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
