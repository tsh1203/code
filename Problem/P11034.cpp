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
string s,t,r="rioi",r2="RIOI";
bool pd(string s){
	for(int i=0;i<s.length()-3;i++){
		int f=0;
		for(int j=0;j<4;j++){
			if(s[i+j]!=r[j]&&s[i+j]!=r2[j])f=1;
		}
		if(f==0)return 1;
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	cin>>s>>t;
	int f1=pd(s),f2=pd(t);
	if(!f1&&!f2)cout<<"Try again!";
	else if(f1&&f2)cout<<"Either is ok!";
	else if(f1)cout<<s<<" for sure!";
	else if(f2)cout<<t<<" for sure!";
	
	return 0;
}
