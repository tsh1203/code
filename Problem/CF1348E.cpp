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
const int N=502;
int n,k,a[N],b[N],sa,sb;
int f[N][N];
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n,k);
	for(int i=1;i<=n;i++)read(a[i],b[i]),sa+=a[i],sb+=b[i];
	if((sa+sb)/k==sa/k+sb/k){
		write((sa+sb)/k);
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			f[i][j]=f[i-1][(j+k-a[i]%k)%k];
			for(int l=0;l<=min(k-1,a[i])&&!f[i][j];l++){
				if((a[i]-l)%k+b[i]>=k)f[i][j]=f[i-1][(j+k-l)%k];
			}
		}
	}
	int ans=0;
	for(int i=0;i<k;i++){
		if(f[n][i]){
			ans=(sa+sb-i)/k;
			break;
		}
	}
	cout<<ans;
	return 0;
}
