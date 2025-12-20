#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
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
unordered_map<string,int>ser;
int t;
bool is(char c){
	return (c>='0'&&c<='9');
}
//bool check(string s){
//	int cnt=0,num=0,fl=0;
//	for(int i=0;i<s.length();i++){
//		int c=s[i];
//		if(!(is(c)||c=='.'||c==':'))return 0;
//		if(is(c)){
//			num=num*10+c-'0'; 
//			if((!fl&&num>255)||(fl&&num>65535))return 0;
//		}
//		else if(c=='.'){
//			if(cnt>3||fl)return 0;
//			if(num==0&&s[i-2]=='0'&&s[i-1]=='0'||!is(s[i-1]))
//				return 0;
//			cnt++,num=0;
//		}
//		else{
//			if(cnt!=3)return 0;
//			if(num==0&&s[i-2]=='0'&&s[i-1]=='0'||!is(s[i-1]))
//				return 0;
//			fl=1,num=0;
//		}
//	}
//	if(cnt!=3||fl!=1)return 0;
//	if(num<0||num>65535)return 0;
//	return 1;
//}
string to(int x){
	string s;
	s.clear();
	do{
		s=(char)(x%10+'0')+s;
		x/=10;
	}while(x);
	return s;
}
bool check(int a,int b,int c,int d,int e,string s){
	if(a<0||a>255)return 0;
	if(b<0||b>255)return 0;
	if(c<0||c>255)return 0;
	if(d<0||d>255)return 0;
	if(e<0||e>65535)return 0;
	string x=to(a)+"."+to(b)+"."+to(c)+"."+to(d)+":"+to(e);
	if(s!=x)return 0;
	return 1;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		string op,s;
		int a,b,c,d,e;
		cin>>op>>s;
		if(sscanf(s.c_str(),"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e)!=5){
			cout<<"ERR\n";
			continue;
		}
		if(!check(a,b,c,d,e,s)){
			cout<<"ERR\n";
			continue;
		}
		if(op=="Server"){
			if(ser[s])cout<<"FAIL\n";
			else{
				ser[s]=i;
				cout<<"OK\n";
			}
		}
		else{
			if(!ser[s])cout<<"FAIL\n";
			else cout<<ser[s]<<"\n";
		}
	}
	return 0;
}
