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
int h,w,q;
int hh[250005],ww[250005];
int hhh[250005],www[250005];
string a[250005],b[250005];
void fun(int x,int xx,int y,int yy){
	for(int i=x;i<=xx;i++){
		hhh[i]=hh[x+xx-i];
	}
	for(int i=y;i<=yy;i++){
		www[i]=ww[y+yy-i];
	}
	for(int i=x;i<=xx;i++){
		hh[i]=hhh[i];
	}
	for(int i=y;i<=yy;i++){
		ww[i]=www[i];
	}
//	for(int i=0;i<h;i++){
//		for(int j=0;j<w;j++){
//			cout<<a[hh[i]][ww[j]];
//		}
//		cout<<endl;
//	}
//	cout<<endl;
}
signed main(){
	read(h,w);
	for(int i=0;i<h;i++){
		cin>>a[i];
	}
	read(q);
	for(int i=0;i<=2e5;i++)
		hh[i]=ww[i]=i;
	while(q--){
		int a,b;
		cin>>a>>b;
		a--,b--;
		fun(0,a,0,b);
		fun(a+1,h-1,b+1,w-1);
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<a[hh[i]][ww[j]];
		}
		cout<<endl;
	}
	return 0;
}
