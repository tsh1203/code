#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
struct no{
	int l,r;
	int val,key;
	int sz;
	bool tag;
}f[N];
int cnt,rt;
mt19937 rd(233);
int neww(int v){
	f[++cnt].val=v;
	f[cnt].key=rd();
	f[cnt].sz=1;
	return cnt;
}
void update(int n){
	f[n].sz=f[f[n].l].sz+f[f[n].r].sz+1;
}
void pushdown(int n){
	swap(f[n].l,f[n].r);
	f[f[n].l].tag^=1;
	f[f[n].r].tag^=1;
	f[n].tag=0;
}
void split(int n,int sz,int &x,int &y){
	if(!n)x=y=0;
	else{
		if(f[n].tag)pushdown(n);
		if(f[f[n].l].sz<sz){
			x=n;
			split(f[n].r,sz-f[f[n].l].sz-1,f[n].r,y);
		}
		else{
			y=n;
			split(f[n].l,sz,x,f[n].l);
		}
		update(n);
	}
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(f[x].key<f[y].key){
		if(f[x].tag)pushdown(x);
		f[x].r=merge(f[x].r,y);
		update(x);
		return x;
	}
	else{
		if(f[y].tag)pushdown(y);
		f[y].l=merge(x,f[y].l);
		update(y);
		return y;
	}
}
void reverse(int l,int r){
	int x,y,z;
	split(rt,l-1,x,y);
	split(y,r-l+1,y,z);
	f[y].tag^=1;
	rt=merge(merge(x,y),z);
}
void ldr(int n){
	if(!n)return;
	if(f[n].tag)pushdown(n);
	ldr(f[n].l);
	cout<<f[n].val<<" ";
	ldr(f[n].r);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		rt=merge(rt,neww(i));
	while(m--){
		int l,r;
		cin>>l>>r;
		reverse(l,r);
	}
	ldr(rt);
	return 0;
}
