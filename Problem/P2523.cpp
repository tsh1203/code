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
const int N=302;
int T,n,m,M;
int p[N],q[N],s[N],f[N][N],C[N][N];
void init(int M){
	memset(C,0,sizeof C);
	memset(f,0,sizeof f);
	memset(s,0,sizeof s);
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		}
	}
}
void solve(){
	read(n,m,M);
	init(M);
	for(int i=1;i<=m;i++){
		read(p[i],q[i]),s[q[i]]++;
	}
	for(int i=n;i>0;i--){
		s[i]=s[i]+s[i+1];
		if(s[i]>n-i+1){
			cout<<"NO\n";
			return;
		}
	}
	f[n+1][0]=1;
	for(int i=n;i>0;i--){
		for(int j=0;j<=n-s[i]-i+1;j++){
			for(int k=0;k<=j;k++){
				f[i][j]=(f[i][j]+f[i+1][j-k]*C[j][k])%M;
			}
		}
	}
	cout<<"YES "<<f[1][n-m]<<"\n";
	
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
/*
1
1 1
1 2 1
1 3 3 1

*/
