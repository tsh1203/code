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
const int N=2e5+5;
int n,k;
int a[N],b[N];
bool check(int mid){
	int cnt=0;
	if(mid==0)return 1;
	for(int i=1;i<=n;i++){
		if(a[i]>=mid){
			cnt+=(a[i]-mid)/b[i]+1;
		}
	}
	return (cnt>=k);
}
void solve(){
	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)cin>>b[i];
	int l=1,r=mx,x=0,ans=0,tot=0;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(check(mid)){
			x=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			int m=(a[i]-(x+1))/b[i]+1,l=a[i]-(m-1)*b[i];
			ans+=m*(a[i]+l)>>1;
			tot+=m;
		}
	}
	if(tot<k)ans+=(k-tot)*x;
	write(ans),endline();
}
signed main(){
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
