#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define memax(a) memset(a,127,sizeof a)
#define memin(a) memset(a,128,sizeof a)
#define mem(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define FIO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,m,w[N];
vector<int>e[N];
stack<int>s;
int dfn[N],b[N],vis[N],low[N],color[N],num[N];
int tot,cnt,ans;
int mi[N],ct[N];
void update(int x){
	s.pop();
	color[x]=tot;
	num[tot]++;
	vis[x]=false;
}
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	s.push(x);
	vis[x]=b[x]=true;
	for(auto q:e[x]){
		if(!dfn[q]){
			tarjan(q);
			low[x]=min(low[x],low[q]);
		}
		else if(vis[q])low[x]=min(low[x],dfn[q]);
	}
	if(low[x]==dfn[x]){
		tot++;
		while(s.top()!=x){
			int t=s.top();
			update(t);
		}
		update(x);
	}
}
signed main(){
	FIO;
	memax(mi);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!b[i])tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(mi[color[i]]>w[i])mi[color[i]]=w[i],ct[color[i]]=1;
		else if(mi[color[i]]==w[i])ct[color[i]]++;
	}
	int ans=0,an=1;
	for(int i=1;i<=n;i++){
		if(mi[i]<1e12)ans+=mi[i],an=an*ct[i]%mod;
	}
	cout<<ans<<" "<<an;
	return 0;
}
