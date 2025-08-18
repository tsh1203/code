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
const int N=100005;
int n,k;
int p1[N],p2[N];
long long ans=0;
struct no{
	int a,b,c;
};
no a[N];
no tmp[N];
int s[N];
void update(int x,int y){
	for(;x<=n;x+=x&-x){
		s[x]+=y;
	}
}
int sum(int x){
	if(x<=0)return 0;
	int ans=0;
	for(;x>0;x-=x&-x){
		ans+=s[x];
	}
	return ans;
}
bool cmp(no p1,no p2){
	if(p1.a!=p2.a)return p1.a<p2.a;
	return p1.b>p2.b;
}
void solve(int l,int r){
	if(l>=r)return;
	int mid=l+(r-l)/2;
	solve(l,mid);
	solve(mid+1,r);
	int cnt1=l;
	for(int cnt2=mid+1;cnt2<=r;++cnt2){
		while(cnt1<=mid&&a[cnt1].b>a[cnt2].b){
			update(a[cnt1].c,1);
			cnt1++;
		}
		int cnt=a[cnt2].c;
		ans+=sum(cnt-k-1);
		if(cnt+k<=n){
			ans+=(sum(n)-sum(cnt+k));
		}
	}
	for(int i=l;i<cnt1;i++){
		update(a[i].c,-1);
	}
	int i=l,j=mid+1,t=l;
	while(i<=mid&&j<=r){
		if(a[i].b>a[j].b)tmp[t++]=a[i++];
		else tmp[t++]=a[j++];
	}
	while(i<=mid)tmp[t++]=a[i++];
	while(j<=r)tmp[t++]=a[j++];
	for(int x=l;x<=r;x++){
		a[x]=tmp[x];
	}
}
signed main(){
	read(n,k);
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		p1[x]=i;
	}
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		p2[x]=i;
	}
	for(int v=1;v<=n;v++){
		a[v]={p1[v],p2[v],v};
	}
	sort(a+1,a+n+1,cmp);
	solve(1,n);
	write(ans);
	return 0;
}
