#include<bits/stdc++.h>
#define int long long
#define endl "\n"
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
}//Orz lby 
using namespace FastIO;
int n;
int a[10000007],d[10000007];
int s[10000007],top;
int ch[10000007][2];
int lrs,rrs;
signed main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)
	{
		while(top&&a[s[top]]>a[i])
			ch[i][0]=s[top--];
		if(s[top])ch[s[top]][1]=i;
		s[++top]=i;
	}
	for(int i=1;i<=n;++i)
	{
		lrs^=(int)(i*(ch[i][0]+1ll));
		rrs^=(int)(i*(ch[i][1]+1ll));
	}
	write(lrs,rrs);
	return 0;
}
