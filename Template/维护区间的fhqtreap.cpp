#include <iostream>
#include <ctime>
#include <cstdio>
const int maxn = 1e5+5;
struct Node
{
    int l,r;
    int val,key;
    int size;
    bool reverse;
}fhq[maxn];
int cnt,root;
#include <random>
std::mt19937 rnd(233);
inline int newnode(int val)
{
    fhq[++cnt].val=val;
    fhq[cnt].key=rnd();
    fhq[cnt].size=1;
    return cnt;
}
inline void update(int now)
{
    fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
inline void pushdown(int now)
{
    std::swap(fhq[now].l,fhq[now].r);
    fhq[fhq[now].l].reverse^=1;
    fhq[fhq[now].r].reverse^=1;
    fhq[now].reverse=false;
}
void split(int now,int siz,int &x,int &y)
{
    if(!now) x=y=0;
    else 
    {
        if(fhq[now].reverse) pushdown(now);
        if(fhq[fhq[now].l].size<siz)
        {
            x=now;
            split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
        }
        else 
        {
            y=now;
            split(fhq[now].l,siz,x,fhq[now].l);
        }
        update(now);
    }
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key)
    {
        if(fhq[x].reverse) pushdown(x);
        fhq[x].r=merge(fhq[x].r,y);
        update(x);
        return x;
    }
    else 
    {
        if(fhq[y].reverse) pushdown(y);
        fhq[y].l=merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
void reverse(int l,int r)
{
    int x,y,z;
    split(root,l-1,x,y);
    split(y,r-l+1,y,z);
    fhq[y].reverse^=1;
    root=merge(merge(x,y),z);
}
void ldr(int now)
{
    if(!now) return;
    if(fhq[now].reverse) pushdown(now);
    ldr(fhq[now].l);
    printf("%d ", fhq[now].val);
    ldr(fhq[now].r);
}
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        root=merge(root,newnode(i));
    while(m--)
    {
        int l,r; scanf("%d%d",&l,&r);
        reverse(l,r);
    }
    ldr(root);
    return 0;
}