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
	int x,y,z;
	friend bool operator > (no a,no b){return a.z>b.z;}
};
int n,m,cnt;
int f[100005];
int res;
priority_queue<no,vector<no>,greater<no> >q;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(no a,no b){
	return a.z<b.z;
}
void kruskal(){
	while(q.size()){
		no e=q.top();
		q.pop();
//		cout<<e.x<<" "<<e.y<<" "<<e.z<<endl;
		int ra=find(e.x);
		int rb=find(e.y);
		if(ra==rb)continue;
		res+=e.z;
		f[ra]=rb;
		cnt++;
		if(cnt==n-1)break;
	}
} 
signed main(){
	read(m,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			read(x);
			if(x<m&&x!=0)q.push({i,j,x});
		}
	}
	n++;
	for(int i=1;i<n;i++)q.push({n,i,m});
	for(int i=1;i<=n;i++)f[i]=i;
	kruskal();
	cout<<res;
	return 0;
}
