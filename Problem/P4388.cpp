#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
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
const int N=1e6+6;
int n,cnt,ans;
int vis[N],p[N],f[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	for(int i=2;i<=n+1;i++){
        if(!vis[i]){
            p[++cnt]=i;
            f[i]=i-1;
        }
        if(n%(i-1)==0)
            ans+=f[i];
        for(int j=1;i*p[j]<=n+1;j++){
            vis[i*p[j]]=1;
            if(i%p[j])
            	f[i*p[j]]=f[i]*f[p[j]];
			else{
				f[i*p[j]]=f[i]*p[j];
                break;
			}
        }
    }
    write((ans+1)>>1);
	return 0;
}
