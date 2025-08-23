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
int n,m;
struct no{
	int idd;
	string u,v,time;
	bool operator < (const no&o)const{
		if(idd!=o.idd)return idd<o.idd;
		if(u!=o.u)return u<o.u;
		if(v!=o.v)return v<o.v;
		return time<o.time;
	}
};
map<string,int>lm;
set<no>ans;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			string s;
			cin>>s;
			lm[s]=i;
		}
	}
	int cnt=m+3;
	for(int i=0;i<n;i++){
		int idd;
		string l;
		cin>>l;
		string cp=l.substr(0,2),u=l.substr(7,3);
		string v=l.substr(11,3),time=l.substr(15,5);
		if(lm.count(cp))idd=lm[cp];
		else idd=++cnt;
		ans.insert({idd,u,v,time});
	}
	cout<<ans.size();
	return 0;
}
