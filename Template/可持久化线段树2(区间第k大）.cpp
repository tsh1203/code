#include<bits/stdc++.h>
#include<map>
#define ll long long
using namespace std;
const int maxn=2e5+7;
const int INF=1e9+7;
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[maxn];
struct node
{
    ll l,r,sum;
}hjt[maxn*40];
vector<ll>v;
ll cnt,root[maxn];
inline ll getid(ll x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1; }
void Insert(ll l,ll r,ll pre,ll &now,ll p)
{
    hjt[++cnt]=hjt[pre];
    now=cnt;
    hjt[now].sum++;
    if(l==r) return ;
    ll mid=(l+r)>>1;
    if(p<=mid)  Insert(l,mid,hjt[pre].l,hjt[now].l,p);
    else    Insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
}
ll q(ll l,ll r,ll L,ll R,ll k)
{
    if(l==r)    return l;
    ll mid=(l+r)>>1;
    ll temp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;
    if(temp>=k) return q(l,mid,hjt[L].l,hjt[R].l,k);
    else return q(mid+1,r,hjt[L].r,hjt[R].r,k-temp);
}
int main()
{
    ll n=read(),m=read();
    for(int i=1;i<=n;i++)
        v.push_back(a[i]=read());
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    
    for(int i=1;i<=n;i++)
    Insert(1,n,root[i-1],root[i],getid(a[i]));
    
    
    for(int i=1;i<=m;i++)
    {
        ll l=read(),r=read(),k=read();
        printf("%lld\n",v[q(1,n,root[l-1],root[r],k)-1]);
    }
    return 0;
}
