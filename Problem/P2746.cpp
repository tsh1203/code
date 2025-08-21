#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>e[N];
stack<int>s;
int n,m;
int dfn[N],low[N],color[N],in[N],out[N];
bool vis[N];
int tot,cnt,ans1,ans2;
void tarjan(int x){
    dfn[x]=low[x]=++cnt;
    s.push(x);
    vis[x]=true;
    for(auto q:e[x]){
        if(!dfn[q]){
            tarjan(q);
            low[x]=min(low[x],low[q]);
        }
        else if(vis[q])low[x]=min(low[x],dfn[q]);
    }
    if(low[x]==dfn[x]){
        tot++;
        while(true){
            int t=s.top();
            s.pop();
            vis[t]=false;
            color[t]=tot;
            if(t==x)break;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x&&x!=0){
            e[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(auto q:e[i]){
            if(color[i]!=color[q]){
                out[color[i]]++;
                in[color[q]]++;
            }
        }
    }
    for(int i=1;i<=tot;i++){
        if(in[i]==0)ans1++;
        if(out[i]==0)ans2++;
    }
    cout<<ans1<<endl;
    if(tot==1)cout<<0<<endl;
    else cout<<max(ans1,ans2)<<endl;
    return 0;
}
