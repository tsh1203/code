#include<bits/stdc++.h>
using namespace std;
const int F=5005;
int f,r;
vector<pair<int,int>> e[F];
int dfn[F],low[F],tot;
int an[F],cnt;
stack<int> st;
void tarjan(int u,int p_edge_id){
    dfn[u]=low[u]=++tot;
    st.push(u);
    for(auto& edge:e[u]){
        int v=edge.first;
        int edge_id=edge.second;
        if(edge_id==p_edge_id)continue;
        if(!dfn[v]){
            tarjan(v,edge_id);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        cnt++;
        while(true){
            int curr=st.top();
            st.pop();
            an[curr]=cnt;
            if(curr==u)break;
        }
    }
}
int b[F];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>f>>r;
    for(int i=0;i<r;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back({v,i});
        e[v].push_back({u,i});
    }
    for(int i=1;i<=f;++i){
        if(!dfn[i]){
            tarjan(i,-1);
        }
    }
    if(cnt==1){
        cout<<0<<endl;
        return 0;
    }
    for(int u=1;u<=f;u++){
        for(auto& edge:e[u]){
            int v=edge.first;
            if(an[u]!=an[v]){
                b[an[u]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(b[i]==1){
            ans++;
        }
    }
    cout<<(ans+1)/2;
    return 0;
}
