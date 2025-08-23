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
signed main(){
	char x,y;
	int z;
	cin>>x>>y>>z;
	if(x=='A'&&y=='N'&&z==2)cout<<"A320";
	if(x=='A'&&y=='W'&&z==2)cout<<"A350";
	if(x=='A'&&y=='W'&&z==4)cout<<"A380";
	if(x=='B'&&y=='N'&&z==2)cout<<"B737";
	if(x=='B'&&y=='W'&&z==4)cout<<"B747";
	if(x=='B'&&y=='W'&&z==2)cout<<"B787";
	if(x=='C'&&y=='N'&&z==2)cout<<"C919";
	return 0;
}
