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
const int N=400;
int n,l[N],c[N],mi=1e18;
map<int,int>f[N];
void upd(int i,int l){
	for(auto x:f[i-1]){
		int j=x.first;
		if(!f[i][j])f[i][j]=f[i-1][j];
		else f[i][j]=min(f[i][j],f[i-1][j]);
		if(!f[i][gcd(j,l)]&&gcd(j,l)!=j)f[i][gcd(j,l)]=f[i-1][j]+c[i];
		else f[i][gcd(j,l)]=min(f[i][gcd(j,l)],f[i-1][j]+c[i]);
	}
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(l[i]);
	for(int i=1;i<=n;i++)read(c[i]);
	f[1][l[1]]=c[1];
	f[1][0]=0;
	if(f[1][1])mi=c[1];
	for(int i=2;i<=n;i++){
		upd(i,l[i]);
		if(f[i][1])mi=min(mi,f[i][1]);
//		for(auto x:f[i]){
//			cout<<"{"<<x.first<<" "<<x.second<<"} ";
//		}	
//		cout<<endl;
	}
	if(mi!=1e18)cout<<mi;
	else cout<<-1;
	return 0;
}
//9 4
