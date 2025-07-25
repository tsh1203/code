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
const int N=1000006;
int n;
int m,ctn,rk[2*N],lst[N],sa[2*N],SB[N],cnt[N];
char s[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	scanf("%s",s+1);
	n=strlen(s+1);
	m=128;
	for(int i=1;i<=n;i++)
		cnt[rk[i]=s[i]]++;
	for(int i=1;i<=m;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)
		sa[cnt[rk[i]]--]=i;
	for(int i=1;;i<<=1,m=ctn){
		int tot=0;
		memset(cnt,0,sizeof(cnt));
		for(int j=n-i+1;j<=n;j++)
			SB[++tot]=j;
		for(int j=1;j<=n;j++)
			if(sa[j]>i)
				SB[++tot]=sa[j]-i;
		for(int j=1;j<=n;j++)
			cnt[rk[j]]++;
		for(int j=1;j<=m;j++)
			cnt[j]+=cnt[j-1];
		for(int j=n;j>=1;j--)
			sa[cnt[rk[SB[j]]]--]=SB[j];
		memcpy(lst,rk,sizeof(lst));
		ctn=0;
		for(int j=1;j<=n;j++){
			if(lst[sa[j]]==lst[sa[j-1]]&&lst[sa[j]+i]==lst[sa[j-1]+i])
				rk[sa[j]]=ctn;
			else rk[sa[j]]=++ctn;
		}
		if(ctn==n)break;
	}
	for(int i=1;i<=n;i++)
		write(sa[i]);
	return 0;
}
