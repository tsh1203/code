#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int __int128
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
const int N=20;
int k,ans;
int A[N][N],B[N][N];
int n,x,y;
bool cl(int a,int x,int y){
	int f=1;
	int t1=a,t2=x,t3=y;
	while(a||x||y){
		if(A[a%10][x%10]!=y%10){
			f=0;
		}
		a/=10,x/=10,y/=10;
	}
	if(f)return 1;
	a=t1,x=t2,y=t3;
	while(a||x||y){
		if(B[a%10][x%10]!=y%10){
			return 0;
		}
		a/=10,x/=10,y/=10;
	}
	return 1;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(k);
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			read(A[i][j]);
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			read(B[i][j]);
		}
	}
	read(n,x,y);
	for(int i=n;i>0;){
		ans+=cl(i,x,y);
		int t=i,cnt=0;
		while(t%10==0&&t)t/=10,cnt++;
		if(t==0)break;
		t--;
		while(cnt--)t=t*10+k-1;
		i=t;
//		cout<<ans<<"---\n";
	}
	write(ans);
	return 0;
}