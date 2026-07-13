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
const int N=1e3+3;
int n,m,k,w;
int f[N][N],vis[N][N],xx[N],yy[N];
bool check(int p,int x,int y){
	bool fl=0;
	if(x>k){
		if(y>=w)return 1;
		return 0;
	}
	int i=xx[x],j=yy[x];
	for(int k=max(1ll,i-p);k<=min(i+p,n);k++){
		if(vis[k][j]==0)y+=f[k][j];
		vis[k][j]++;
	}
	fl|=check(p,x+1,y);
	for(int k=max(1ll,i-p);k<=min(i+p,n);k++){
		if(vis[k][j]==1)y-=f[k][j];
		vis[k][j]--;
	}
	
	for(int k=max(j-p,1ll);k<=min(j+p,m);k++){
		if(vis[i][k]==0)y+=f[i][k];
		vis[i][k]++;
	}
	fl|=check(p,x+1,y);
	for(int k=max(j-p,1ll);k<=min(j+p,m);k++){
		if(vis[i][k]==1)y-=f[i][k];
		vis[i][k]--;
	}
	if(fl)return 1;
	return fl;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,m,k,w);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(f[i][j]);
		}
	}
	for(int i=1;i<=k;i++)cin>>xx[i]>>yy[i];
	int L=-1,R=1001;
	if(check(R,1,0)==0){
		cout<<"Impossible";
		return 0;
	}
	while(L+1<R){
		int mid=(L+R)>>1;
		if(check(mid,1,0))R=mid;
		else L=mid;
	}	
	cout<<R;
	return 0;
}