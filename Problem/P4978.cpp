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
const int mod=998244353,N=2e3+3;
int n,m;
int a[N],b[N];
vector<int>va,vb;
int ksm(int a,int b){
	int res=1;a%=mod;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int inv(int n){return ksm(n,mod-2);}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=m;i++)read(b[i]);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			cnt+=a[j],va.push_back(cnt);
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=i;j<=m;j++){
			cnt+=b[j],vb.push_back(cnt);
		}
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	int ans=0,p=0,sz=vb.size();
	for(auto x:va){
		while(p<sz&&vb[p]<x)p++;
		ans=(ans+p)%mod;
	}
	int as=(n*(n+1)/2)%mod;
	int bs=(m*(m+1)/2)%mod;
	write(ans*inv(as*bs%mod)%mod);
	return 0;
}
