#include<bits/stdc++.h>
#pragma __gnu_cxx(O3)
#pragma __gnu_cxx(Ofast)
#define lowbit(x) (x&-x)
#define fir first
#define sec second
#define otto auto
#define mid ((l+r)/2)
#define getbit(x,y) (((x)>>(y))&1)
#define bit(x) ((int)1<<(x))
//#define frd
//#define int ll
//#define fre "string"
namespace FastIO {
#ifdef frd
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++)	
#define flush() fwrite(obuf,O-obuf,1,stdout);
#define putchar(ch) *O++=ch;
	constexpr auto maxn=1<<23;char buf[maxn],*p1=buf,*p2=buf,obuf[maxn],*O=obuf;class FLUSH{public:~FLUSH(){flush();}}Flush;
#endif
	namespace india250604 {
		char getch() {return getchar();}bool chk_(const char&x){return isgraph(x)||x==EOF;}
		void _read(char &x) {x=getchar();while(!chk_(x))x=getchar();}
		void Cread(char *l,char *r) {char *cur=l;_read(*cur);cur++;while(cur!=r){*cur=getchar();++cur;}}
		char *Cread(char *l) {char *cur=l;_read(*cur);cur++;while(isgraph(*cur=getchar()))++cur;*cur=0;return cur;}
		template<typename T>void _read(T &x) {char t=getchar();bool tmp=0;x=0;while(t<'0'||t>'9'){if(t=='-')tmp=1;t=getchar();};while('0'<=t&&t<='9'){x=(x<<1)+(x<<3)+(t^48);t=getchar();}if(tmp)x=-x;}
		void read(){}template<typename T,typename ...T2>void read(T &x,T2 &...oth) {_read(x);read(oth...);}
		template<typename T>void read(T *l,T *r) {T *cur=l;while(cur!=r){_read(*cur);++cur;}}
		void Aread(){}template<typename T,typename ...T2>void Aread(T *&x,T2 *&...oth) {_read(*x++);Aread(oth...);}
		template<typename T,typename ...T2>void Aread(T n,T2 *...oth) {while(n--) Aread(oth...);}
		void _write(char x=' ') {putchar(x);}void _write(const char*x) {while(*x)putchar(*x++);}
		void _Cwrite(char*x) {while(*x)putchar(*x++);}
		template<typename T>void _write(T x) {if(x<0){putchar('-');x=-x;}if(x/10)_write(x/10);putchar((x%10)^48);}
		template<typename T>void _write(T x,T y) {if(x<0){putchar('-');x=-x;}if(x/y)_write(x/y,y);putchar((x%y)^48);}
		void write(){putchar('\n');}template<typename T>void write(const T&x) {_write(x);putchar('\n');}
		template<typename T,typename ...T2>void write(const T&x,const T2&...oth) {_write(x);putchar(' ');write(oth...);}
		template<typename T>void Awrite(T *l,T *r,char ch=' ',char ed='\n') {if(l==r) {putchar(ed);return;}T *cur=l;_write(*cur);++cur;while(cur!=r){if(ch)putchar(ch);_write(*cur);++cur;}if(ed)putchar(ed);}
		template<typename T>void write(T*l,T*r){Awrite(l,r);}
	}}
using namespace FastIO::india250604;
#ifdef fre
void fropen(const std::string&s) {freopen((s+".in").c_str(),"r",stdin);freopen((s+".out").c_str(),"w",stdout);}
signed __main__();signed main() {fropen(fre);return __main__();}
#define main __main__
#endif
#ifdef frd
#undef getchar
#undef putchar
#endif

signed main() {return YJDsoCute::main();}
/*
https://www.boxim.online/file/box-im/image/20250723/1753270095984.png
https://www.boxim.online/file/box-im/image/20250723/1753270107438.png
https://www.boxim.online/file/box-im/image/20250723/1753270115258.png
https://www.boxim.online/file/box-im/image/20250723/1753270125501.png
https://www.boxim.online/file/box-im/image/20250723/1753270185990.png
最后一张Aread->Awrite
*/
