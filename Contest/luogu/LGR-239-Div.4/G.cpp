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
namespace FastIO{
	void read(){}
	template<class T1,class...T2>inline void read(T1 &x,T2&...oth){
		bool pd=0;x=0;char ch=getchar();
		while(!isdigit(ch)){pd|=ch=='-';ch=getchar();}
		while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		x=pd?-x:x;
		read(oth...);
	}
	template<class T>void _write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9)_write(x/10);
		putchar(x%10^48);
	}
	void write(){}
	template<class T1,class...T2>inline void write(T1 x,T2...oth){_write(x);putchar(' ');write(oth...);}
	inline void endline(){putchar('\n');}
}
using namespace FastIO;
const int N=102;
int n,q;
int y[N][N],t[N][N],f[N][N];
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>y[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>t[i][j];
	while(q--){
		int x,yy;
		cin>>x>>yy;
		int ans=-1;
		if(y[x][yy]!=-1)ans=y[x][yy];
		for(int w=1;w<=n;w++){
			if(w==x||w==yy)continue;
			if(t[x][w]!=-1&&t[w][yy]!=-1){
				if(ans==-1||t[x][w]+t[w][yy]<ans)
					ans=t[x][w]+t[w][yy];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
