#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],id[N],cnt,f[N];
map<int,int>kk;
set<int,greater<int> >st;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!kk[a[i]])kk[a[i]]=++cnt;
        a[i]=kk[a[i]];
    }
    memset(f,127,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        if(id[a[i]])st.erase(st.find(id[a[i]]));
        int w=1;
        for(auto x:st){
            int p=x;
            f[i]=min(f[i],f[p]+w*w);
            if(w*w>=f[i])break;
            w++;
        }
        f[i]=min(f[i],w*w);
        f[i]=min(f[i],f[i-1]+1);
        id[a[i]]=i;st.insert(i);
    }
    cout<<f[n];
    return 0;
}
