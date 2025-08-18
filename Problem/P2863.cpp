#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>e[N];
stack<int>s;
int n,m;
int dfn[N],b[N],vis[N],low[N],color[N],num[N];
int tot,cnt,ans;
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
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!b[i])tarjan(i);
    }
    for(int i=1;i<=tot;i++){
        if(num[i]>1)ans++;
    }
    cout<<ans;
    return 0;
}
