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
const int N=1e5+5,M=2e5+5;
const int INF=1e18;
struct no{
	int to,nxt;
	int val;
}e[M];
int n,k,m;
int s,t;
int head[N],tot=1;
int a[N];
int dis[N],cur[N];
vector<int>b[N],ans[30];
void add(int u,int v,int w){
	e[++tot]={v,head[u],w},head[u]=tot;
	e[++tot]={u,head[v],0},head[v]=tot;
}
bool bfs(){
	memset(dis,0,sizeof(dis));
	queue<int>q;
	q.push(s);
	dis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(e[i].val>0&&!dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[t]>0;
}

int dfs(int u,int flow){
	if(u==t)
		return flow;
	int used=0;
	for(int &i=cur[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(e[i].val>0&&dis[v]==dis[u]+1){
			int f=dfs(v,min(flow-used,e[i].val));
			if(f>0){
				e[i].val-=f;
				e[i^1].val+=f;
				used+=f;
				if(used==flow)
					break;
			}
		}
	}
	return used;
}

int dinic(){
	int ans=0;
	while(bfs()){
		memcpy(cur,head,sizeof(head));
		ans+=dfs(s,INF);
	}
	return ans;
}

signed main(){
	read(k,n);
	for(int i=1;i<=k;i++){
		read(a[i]);
		m+=a[i];
	}
	s=0,t=n+k+1;
	for(int i=1;i<=n;i++){
		int p;
		read(p);
		for(int j=0;j<p;j++){
			int x;
			read(x);
			b[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		add(s,i,1);
		for(int x:b[i]){
			add(i,n+x,1);
		}
	}
	for(int i=1;i<=k;i++){
		add(n+i,t,a[i]);
	}
	
	int mx=dinic();
	if(mx!=m){
		cout<<"No Solution!";
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=head[i];j;j=e[j].nxt){
				int v=e[j].to;
				if(v>n&&v<=n+k&&e[j].val== 0){
					int x=v-n;
					ans[x].push_back(i);
				}
			}
		}
		for(int i=1;i<=k;i++){
			cout<<i<<":";
			for(auto j:ans[i]){
				cout<<j<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
