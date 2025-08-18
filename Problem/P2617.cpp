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
		if(x>9)_write(x/10);
		putchar(x%10^48);
	}
	void write(){}
	template <class T1,class ... T2>
	inline void write(T1 x,T2 ...oth){_write(x);putchar(' ');write(oth...);}
	inline void endline(){putchar('\n');}
}//Orz lby 
using namespace FastIO;

const int N=1e6+6,inf=1e9;

int n,m;
int a[N],ans[N];
int tr[N],tot;

struct no{
	int type,id,val,l,r,k;
};
no q[N],q1[N],q2[N];
int s;

int lb(int x){
	return x&-x;
}

void add(int x,int y){
	while(x<=n){
		tr[x]+=y;
		x+=x&(-x);
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans+=tr[x];
		x-=x&(-x);
	}
	return ans;
}
void solve(int l,int r,int ql,int qr){
	if(ql>qr)return;
	if(l==r){
		for(int i=ql;i<=qr;i++)
			if(q[i].type==2)
				ans[q[i].id]=l;
		return;
	}
	
	int mid=(l+r)>>1;
	int cnt1=0,cnt2=0;
	
	for(int i=ql;i<=qr;i++){
		if(q[i].type==1){
			if(q[i].val<=mid){
				add(q[i].l,q[i].k);
				q1[++cnt1]=q[i];
			}
			else q2[++cnt2]=q[i];
		}
		else{
			int t=sum(q[i].r)-sum(q[i].l-1);
			if(q[i].k>t){
				q[i].k-=t;
				q2[++cnt2]=q[i];
			}
			else q1[++cnt1]=q[i];
		}
	}
	for(int i=1;i<=cnt1;i++)
		if(q1[i].type==1)add(q1[i].l,-q1[i].k);
	for(int i=1;i<=cnt1;i++)q[ql+i-1]=q1[i];
	for(int i=1;i<=cnt2;i++)q[ql+cnt1+i-1]=q2[i];
	
	solve(l,mid,ql,ql+cnt1-1);
	solve(mid+1,r,ql+cnt1,qr);
}

signed main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		q[++s]={1,0,a[i],i,0,1};
	}
	
	for(int i=1;i<=m;i++){
		char op;
		cin>>op;
		if(op=='Q'){
			int l,r,k;
			read(l,r,k);
			q[++s]={2,++tot,0,l,r,k};
		}
		else{
			int x,y;
			read(x,y);
			q[++s]={1,0,a[x],x,0,-1};
			q[++s]={1,0,y,x,0,1};
			a[x]=y;
		}
	}
	
	solve(-inf,inf,1,s);
	
	for(int i=1;i<=tot;i++)
		write(ans[i]),endline();
	
	return 0;
}
