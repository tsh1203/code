#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
mt19937 rd(233);
int n,mi;
int rt,cnt,tag;
int le;
struct no{
	int l,r;
	int val,key;
	int sz;
}f[N];
int neww(int val){
	f[++cnt].val=val;
	f[cnt].key=rand();
	f[cnt].sz=1;
	return cnt;
}
void update(int n){
	f[n].sz=f[f[n].l].sz+f[f[n].r].sz+1;
}
void split(int n,int val,int &x,int &y){
	if(!n)x=y=0;
	else if(f[n].val>=val){
		split(f[n].l,val,x,y),f[n].l=y,update(y=n);
	}
	else
	{
		split(f[n].r,val,x,y),f[n].r=x,update(x=n);
	}
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(f[x].key<f[y].key){
		f[x].r=merge(f[x].r,y);
		update(x);
		return x;
	}
	else{
		f[y].l=merge(x,f[y].l);
		update(y);
		return y;
	}
}
void ins(int val){
	int x,y;
	split(rt,val,x,y);
	rt=merge(merge(x,neww(val)),y);
}
void leave(){
	int x,y;
	split(rt,mi-tag,x,y);
	le+=f[x].sz;
	rt=y;
}
int ans(int n,int r){
	int rank=f[f[n].l].sz+1;
	if(r==rank)return f[n].val;
	else if(r<rank)return ans(f[n].l,r);
	else return ans(f[n].r,r-rank);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	f[0].sz=0;
	cin>>n>>mi;
	for(int i=1;i<=n;i++)
	{
		char c[3]; int k;
		cin>>c>>k;
		if(c[0]=='I'&&k>=mi)
			ins(k-tag);
		else if(c[0]=='A')
			tag+=k;
		else if(c[0]=='S'){
			tag-=k;
			leave();
		}
		else if(c[0]=='F')
		{
			if(k>f[rt].sz)
				cout<<"-1\n";
			else
				cout<<ans(rt,f[rt].sz-k+1)+tag<<"\n";
		}
	}
	cout<<le;
	return 0;
}
