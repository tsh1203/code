#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
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
int n,m,k;
pii a[2003];
int f[2003];
bool cmp(pii a,pii b){
	if(a.first!=b.first)return a.first<b.first;
	return a.second<b.second;
}
int d(pii a){
	return min(a.first,a.second);
}
int mi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	if(a==0)return 0;
	if(b==0||b==a)return 1;
	if(b>a/2)b=a-b;
	int ans=1;
	for(int i=a;i>=a-b+1;i--)
	{
		ans*=i,ans%=mod;
	}
	for(int i=1;i<=b;i++)
	{
		ans*=mi(i,mod-2);
		ans%=mod;
	}
	return ans;
}
int fun(int x,int y){
	return C(x+y-2,y-1);
}
signed main(){
	read(n,m,k);
	for(int i=1;i<=k;i++){
		read(a[i].first,a[i].second);
		if(a[i].first==1&&a[i].second==1||a[i].first==n&&a[i].second==m){
			cout<<0;
			return 0;
		}
	}
	
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
		f[i]=fun(a[i].first,a[i].second);
	for(int i=1;i<=k;i++){
		int x=a[i].first,y=a[i].second;
		for(int j=1;j<=k;j++){
			if(a[j].first>=x&&a[j].second>=y&&i!=j){
				f[j]=(mod*10000+f[j]-(fun(a[j].first-x+1,a[j].second-y+1)*f[i])%mod)%mod;
			}
		}
	}
	int ans=fun(n,m);
	for(int i=1;i<=k;i++){
		int x=a[i].first,y=a[i].second;
		ans=(mod*10000+ans-(fun(n-x+1,m-y+1)*f[i])%mod)%mod;
	}
	cout<<ans;
	return 0;
}
