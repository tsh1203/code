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
const int N=5e5+5,M=2e7+7;
int n,v[N],f[N];
bool p[M];
vector<int>e[N];
void dfs(int x,int y){
	f[x]=y;
	if(p[v[x]]==0)y=max(v[x],y);
	for(auto v:e[x]){
		if(!f[v]){
			dfs(v,y);
		}
	}
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++)read(v[i]);
	for(int i=1,u,v;i<n;i++){
		read(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	p[1]=1;
	for(int i=2;i<=1e7;i++){
		if(p[i]==0){
			for(int j=2*i;j<=1e7;j+=i){
				p[j]=1;
			}
		}
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}