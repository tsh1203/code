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
const int N=1003;
struct no{int x,y;};
int n,m,q;
int b[N],d[N][N];
vector<int>ed[N];
queue<no>que;
double cnt[N],ans;
void bfs(int s){
	for(int i=1;i<=n;i++)d[s][i]=1e18;
	queue<int>que;
	que.push(s);
	d[s][s]=0;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(auto v:ed[u]){
			if(d[s][v]==1e18) {
				d[s][v]=d[s][u]+1;
				que.push(v);
			}
		}
	}
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
	read(n,m,q);
	for(int i=1;i<=m;i++){
		int a,b;
		read(a,b);
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(d[x][i]<=y)ans++;
		}
	}
	cout<<fixed<<setprecision(2)<<ans/(double)q;
	return 0;
}
