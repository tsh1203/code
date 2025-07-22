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
int n,a[100005];
int ls[100005],rs[100005],b[100005];
void dfs(int x){
	write(x);
	if(ls[x]) dfs(ls[x]);
	if(rs[x]) dfs(rs[x]);
}
int s[10000007],top;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	read(n);
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		a[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		while(top&&a[s[top]]>a[i])
			flag=s[top],top--;
		if(top)rs[s[top]]=i;
		if(flag)ls[i]=flag;
		s[++top]=i;
	}
	for(int i=1;i<=n;i++){
		b[ls[i]]=1;
		b[rs[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			dfs(i);
			break;
		}
	}
	return 0;
}
