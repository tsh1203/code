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
const int N=200;
int n,f[N],p[N],b[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa!=fb)f[fa]=fb;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(p[i]),b[p[i]]=i;
		f[i]=i;
	}
	for(int i=1,d;i<=n;i++){
		cin>>d;
		if(i-d>0)merge(i,i-d);
		if(i+d<=n)merge(i,i+d);
	}
	for(int i=1;i<=n;i++){
		if(find(i)!=find(b[i])){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}

