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
int n,m,q;
int a[102][102];
int b[102][102];
int dx[10]={0,-1,1,0,0};
int dy[10]={0,0,0,-1,1};
bool ck(int xx,int yy){
	if(xx==0||xx==n+1||yy==0||yy==m+1)
		return 1;
	return 0;
}
signed main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(b,0,sizeof b);
		int cnt=0;
		while(!ck(x,y)){
			if(b[x][y]){
				cnt=-1;
				break;
			}
			b[x][y]=1;
			int xx=x+dx[a[x][y]];
			int yy=y+dy[a[x][y]];
			x=xx,y=yy;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
