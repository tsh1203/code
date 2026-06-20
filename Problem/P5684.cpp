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
const int mod=1e9+7;
int n,a[30],ans=1,an=1,cnt,f;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[x-'a']++;
		ans=ans*i%mod;
	}
	for(int i=0;i<26;i++){
		if(a[i]&1)cnt++,f=i;
	}
	if(cnt>1){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n/2;i++)an=an*i%mod;
	for(int i=0;i<26;i++)
		for(int j=a[i]/2+1;j<=a[i];j++)
			an=an*j%mod;
//	if(cnt)an=an*a[f]%mod;
	cout<<(ans-an+mod)%mod;
	return 0;
}
