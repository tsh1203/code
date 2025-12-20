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
struct no{
	int mx,sc;
};
int n;
vector<no>a,b,c;
int sum;
void init(){
	a.clear(); 
	b.clear(); 
	c.clear(); 
	sum=0;
}
bool cmp(no a,no b){
	return a.mx-a.sc<b.mx-b.sc;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	int T;
	read(T);
	while(T--){
		init();
		read(n);
		int la=0,lb=0,lc=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			read(x,y,z);
			if(x>=y&&x>=z)a.push_back({x,max(y,z)}),la++;
			else if(y>=x&&y>=z)b.push_back({y,max(x,z)}),lb++;
			else if(z>=y&&z>=x)c.push_back({z,max(x,y)}),lc++;
			sum+=max(x,max(y,z));
		}
		if(la>n/2){
			sort(a.begin(),a.end(),cmp);
			int i=0;
			while(la>n/2&&i<a.size()){
				sum-=(a[i].mx-a[i].sc);
				i++,la--;
			}
		}
		else if(lb>n/2){
			sort(b.begin(),b.end(),cmp);
			int i=0;
			while(lb>n/2&&i<b.size()){
				sum-=(b[i].mx-b[i].sc);
				i++,lb--;
			}
		}
		else{
			sort(c.begin(),c.end(),cmp);
			int i=0;
			while(lc>n/2&&i<c.size()){
				sum-=(c[i].mx-c[i].sc);
				i++,lc--;
			}
		}
		write(sum),endline();
	}
	
	return 0;
}
