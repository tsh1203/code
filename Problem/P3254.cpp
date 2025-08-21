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
int m,n;
int a[302],b[302];
int ida[302],idb[302];
vector<int>v[302];
int cnt[302];
bool fl=1;
bool cmp(int x,int y){
	return a[x]>a[y];
}
bool cmp2(int x,int y){
	return b[x]>b[y];
}
signed main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ida[i]=i;
		if(a[i]!=a[1])fl=0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		idb[i]=i;
		if(b[i]!=a[1])fl=0;
	}
	if(fl){
		int ans=1;
		cout<<1<<endl;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=a[i];j++){
				cout<<ans<<" ";
				ans=(ans+1)%n+1;
			}
			cout<<endl;
		}
		return 0;
	}
	sort(ida+1,ida+m+1,cmp);
	sort(idb+1,idb+n+1,cmp2);
	for(int i=1;i<=m;i++){
		int x=a[ida[i]];
		for(int j=1;j<=n;j++){
			if(cnt[idb[j]]<b[idb[j]]&&x>0){
				cnt[idb[j]]++;
				x--;
				v[ida[i]].push_back(idb[j]);
			}
		}
		if(x){
			cout<<0;
			return 0;
		}
	}
	cout<<1<<endl;
	for(int i=1;i<=m;i++){
		for(auto x:v[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
