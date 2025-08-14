#include<bits/stdc++.h>
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
const int N=1e5+5;
struct no
{
	int a,b,c,id,cnt;
}a[N];
int n,k;
int f[N],p,tot,s[N],ans[N],d[N];
int kk,ss[N],st[402],ed[402],b[502][502],cb[2*N],cc[2*N];
bool pd(int i,int j){
	return (a[i].a<=a[j].a&&a[i].b<=a[j].b&&a[i].c<=a[j].c);
}
bool cmp(no x,no y){
	if(x.a==y.a){
		if(x.b==y.b)return x.c<y.c;
		else return x.b<y.b;
	}
	return x.a<y.a;
}
void fun(int h){
	memset(b,0,sizeof(b));
	int ct=0;
	for(int i=st[h];i<=ed[h];i++)
		s[++ct]=a[i].b;
	sort(s+1,s+1+ct);
	ct=unique(s+1,s+1+ct)-s-1;
	p=1;
	for(int i=1;i<=k;i++){
		if(i>s[p]&&p<=ct)++p;
		cb[i]=p;
	}
	int ctn=0;
	for(int i=st[h];i<=ed[h];i++)
		s[++ctn]=a[i].c;
	sort(s+1,s+1+ctn);
	ctn=unique(s+1,s+1+ctn)-s-1;
	p=1;
	for(int i=1;i<=k;i++){
		if(i>s[p]&&p<=ctn)++p;
		cc[i]=p;
	}
	for(int i=st[h]-1;i;i--)b[cb[a[i].b]][cc[a[i].c]]+=a[i].cnt;
	for(int i=1;i<=ct;i++)
		for(int j=1;j<=ctn;j++)
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	return;
}
int main()
{
	read(n,k);
	for(int i=1;i<=n;i++){
		read(a[i].a,a[i].b,a[i].c);
		a[i].id=i,a[i].cnt=1;
		f[i]=i;
	}
	sort(a+1,a+1+n,cmp);
	p=0;
	for(int i=1;i<=n;i++){
		if(pd(i,p)){
			++tot;
			f[a[i].id]=a[p].id;
			a[i].a=k+1;
			++a[p].cnt;
		}
		else p=i;
	}
	sort(a+1,a+1+n,cmp);
	n-=tot;
	kk=sqrt(n)+1;
	for(int i=1;i<=n;i++){
		ss[i]=(i-1)/kk+1,ed[ss[i]]=i;
		ans[a[i].id]+=a[i].cnt-1;
	}
	for(int i=n;i;i--)st[ss[i]]=i;
	for(int i=1;i<=ss[n];i++){
		fun(i);
		for(int j=st[i];j<=ed[i];j++){
			for(int k=st[i];k<j;k++)
				if(pd(k,j))
					ans[a[j].id]+=a[k].cnt;
			ans[a[j].id]+=b[cb[a[j].b]][cc[a[j].c]];
		}
	}
	for(int i=1;i<=n+tot;i++)d[ans[f[i]]]++;
	for(int i=0;i<n+tot;i++)write(d[i]),endline();
	return 0;
}
