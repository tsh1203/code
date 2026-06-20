#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=4e5+5,M=2e6+6,INF=1e18;
struct no{int h,l,r;}a[N];
int head[N],to[M],nxt[M],w[M],idx;
void add(int u,int v,int c){
	to[++idx]=v,w[idx]=c,nxt[idx]=head[u],head[u]=idx;
}
int n,H,sx,sy,cnt;
int dis[N],vis[N],vb[N];
bool cmp(no a,no b){return a.h<b.h;}
void build(){
	queue<int> q;
	q.push(n);vb[n]=1;
	while(!q.empty()){
		int i=q.front();q.pop();
		int x=a[i].l;
		for(int j=i-1;j>=0;j--){
			if(a[i].h-a[j].h>H)break;
			if(x>=a[j].l&&x<=a[j].r){
				if(!j)add(i,0,a[i].h);
				else{
					add(i,j,(a[i].h-a[j].h)+(x-a[j].l));
					add(i,j+n,(a[i].h-a[j].h)+(a[j].r-x));
					if(!vb[j])vb[j]=1,q.push(j);
				}
				break;
			}
		}
		x=a[i].r;
		for(int j=i-1;j>=0;j--){
			if(a[i].h-a[j].h>H)break;
			if(x>=a[j].l&&x<=a[j].r){
				if(!j)add(i+n,0,a[i].h);
				else{
					add(i+n,j,(a[i].h-a[j].h)+(x-a[j].l));
					add(i+n,j+n,(a[i].h-a[j].h)+(a[j].r-x));
					if(!vb[j])vb[j]=1,q.push(j);
				}
				break;
			}
		}
	}
}
priority_queue<pii,vector<pii>,greater<pii>>q;
void dij(){
	for(int i=0;i<=2*n;i++)dis[i]=INF;
	dis[n]=dis[n+n]=0;
	q.push({0,n}),q.push({0,n+n});
	while(!q.empty()){
		auto [dd,u]=q.top();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dd+w[i]){
				dis[v]=dd+w[i];
				q.push({dis[v],v});
			}
		}
	}
	cout<<dis[0];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>H>>sx>>sy;
	for(int i=1;i<=n;i++){
		int h,l,r;cin>>h>>l>>r;
		if(h<sy)a[++cnt]={h,l,r};
	}
	n=cnt;
	sort(a+1,a+n+1,cmp);
	a[0]={0,(int)-2e10,(int)2e10};
	a[++n]={sy,sx,sx};
	build();
	dij();
	return 0;
}
