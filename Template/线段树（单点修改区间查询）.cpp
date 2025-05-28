#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000006],ans[1000006<<2],tag[1000006<<2];
int ls(int x)
{
	return x<<1;
}
int rs(int x)
{
	return x<<1|1;
}
void push_up(int p)
{
	ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(int p,int l,int r)
{
	tag[p]=0;
	if(l==r)
	{
		ans[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
} 
void fun(int p,int l,int r,int k)
{
	tag[p]=tag[p]+k;
	ans[p]=ans[p]+k*(r-l+1);
}
void push_down(int p,int l,int r)
{
	int mid=(l+r)>>1;
	fun(ls(p),l,mid,tag[p]);
	fun(rs(p),mid+1,r,tag[p]);
	tag[p]=0;
}
void update(int nl,int nr,int l,int r,int p,int k)
{
	if(nl<=l&&r<=nr)
	{
		ans[p]+=k*(r-l+1);
		tag[p]+=k;
		return ;
	}
	push_down(p,l,r);
	int mid=(l+r)>>1;
	if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
	if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
	push_up(p);
}
int query(int q_x,int q_y,int l,int r,int p)
{
	int res=0;
	if(q_x<=l&&r<=q_y)return ans[p];
	int mid=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
	if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a1,b,c,d,e,f;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		cin>>a1;
		if(a1==1)
		{
			cin>>b>>c>>d;
			update(b,c,1,n,1,d);
		}
		else
		{
			cin>>e>>f;
			cout<<query(e,f,1,n,1)<<"\n";
		}
	}
	return 0;
}
