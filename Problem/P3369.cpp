#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct Node
{
	int l,r;
	int val,key;
	int size;
}f[maxn];
int cnt,root;
mt19937 rnd(233);
inline int newnode(int val)
{
	f[++cnt].val=val;
	f[cnt].key=rnd();
	f[cnt].size=1;
	return cnt;
}
void update(int now)
{
	f[now].size=f[f[now].l].size+f[f[now].r].size+1;
}
void split(int now,int val,int &x,int &y)
{
	if(!now) x=y=0;
	else
	{
		if(f[now].val<=val)
		{
			x=now;
			split(f[now].r,val,f[now].r,y);
		}
		else
		{
			y=now;
			split(f[now].l,val,x,f[now].l);
		}
		update(now);
	}
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	if(f[x].key>f[y].key)
	{
		f[x].r=merge(f[x].r,y);
		update(x);
		return x;
	}
	else
	{
		f[y].l=merge(x,f[y].l);
		update(y);
		return y;
	}
}
int x,y,z;
void ins(int val)
{
	split(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
}
void del(int val)
{
	split(root,val,x,z);
	split(x,val-1,x,y);
	y=merge(f[y].l,f[y].r);
	root=merge(merge(x,y),z);
}
inline void getrank(int val)
{
	split(root,val-1,x,y);
	cout<<f[x].size+1<<"\n";
	root=merge(x,y);
}
void getnum(int rank)
{
	int now=root;
	while(now)
	{
		if(f[f[now].l].size+1==rank)
			break;
		else if(f[f[now].l].size>=rank)
			now=f[now].l;
		else
		{
			rank-=f[f[now].l].size+1;
			now=f[now].r;
		}
	}
	cout<<f[now].val<<"\n";
}
void pre(int val)
{
	split(root,val-1,x,y);
	int now=x;
	while(f[now].r)
		now=f[now].r;
	cout<<f[now].val<<"\n";
	root=merge(x,y);
}
inline void nxt(int val)
{
	split(root,val,x,y);
	int now=y;
	while(f[now].l)
		now=f[now].l;
	cout<<f[now].val<<"\n";
	root=merge(x,y);
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int opt,x;
		cin>>opt>>x;
		switch(opt)
		{
			case 1: ins(x); break;
			case 2: del(x); break;
			case 3: getrank(x); break;
			case 4: getnum(x); break;
			case 5: pre(x); break;
			case 6: nxt(x); break;
		}
	}
	return 0;
}
