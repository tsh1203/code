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

const int N=1000010;
int n,m,cnt;
struct no{
	int x,y,p,opt,k,id,ans;
}a[N],b[N];
int ans[N];

bool cmp(no a,no b)
{
	if(a.x!=b.x) return a.x<b.x;
	else if(a.y!=b.y) return a.y<b.y;
	else return a.opt<b.opt;
}

void merge(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	
	int t1=l,t2=mid+1,p=l; int cnt=0;
	while(t2<=r)
	{
		while(a[t1].y<=a[t2].y&&t1<=mid){
			if(a[t1].opt==1) cnt+=a[t1].p;
			b[p++]=a[t1++];
		}
		if(a[t2].opt==2) a[t2].ans+=cnt;
		b[p++]=a[t2++];
	}
	
	while(t1<=mid) b[p++]=a[t1++];
	while(t2<=r) b[p++]=a[t2++];
	for(int i=l;i<=r;++i) a[i]=b[i];
}

signed main()
{
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		int x,y,z;
		read(x,y,z);
		a[++cnt]={x,y,z,1,0,0,0};
	}
	
	for(int i=1;i<=m;++i)
	{
		int aa,b,c,d;
		read(aa,b,c,d);
		a[++cnt]=(no){c,d,0,2,1,i,0};
		a[++cnt]=(no){aa-1,b-1,0,2,1,i,0};
		a[++cnt]=(no){aa-1,d,0,2,-1,i,0};
		a[++cnt]=(no){c,b-1,0,2,-1,i,0};
	}
	
	sort(a+1,a+1+cnt,cmp);
	
	merge(1,cnt);
	for(int i=1;i<=cnt;++i)
		if(a[i].opt==2) ans[a[i].id]+=a[i].k*a[i].ans;
	
	for(int i=1;i<=m;++i)
		write(ans[i]),endline();
	return 0;
}
