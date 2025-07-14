#include<bits/stdc++.h>
#define int unsigned int
#define endl "\n"
using namespace std;
mt19937 rd(233);
int n,m,sd,rt;
int cnt,ans;
int lst=7;
struct no{
	int ra,rb;
	bool operator < (const no b){
		if(ra==b.ra)return rb<b.rb;
		else return ra>b.ra;
	}
	bool operator <= (const no b){
		if(ra==b.ra)return rb<=b.rb;
		else return ra>=b.ra;
	}
}a[1000006];
struct fhq{
	int l,r;
	int key,sz,cnt;
	no val;
}f[2000006];
void update(int x){
	f[x].sz=f[f[x].l].sz+f[f[x].r].sz+f[x].cnt;
}
int neww(no k){
	int now;
	now=++cnt;
	f[now].sz=f[now].cnt=1;
	f[now].val=k;
	f[now].key=rd();
	f[now].l=f[now].r=0;
	return now;
}

void split(no k,int now,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(f[now].val<=k){
			x=now;
			split(k,f[now].r,f[now].r,y);
		}
		else{
			y=now;
			split(k,f[now].l,x,f[now].l);
		}
		update(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(f[x].key>f[y].key){
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
void ins(no x){
	int l,r;
	split(x,rt,l,r);
	l=merge(l,neww(x));
	rt=merge(l,r);
}
void del(no x){
	int l,a,r;
	no y=x;
	y.rb--;
	split(x,rt,l,r);
	split(y,l,l,a);
	a=merge(f[a].l,f[a].r);
	rt=merge(merge(l,a),r);
}
int ask(no x){
	int l,r;
	x.rb--;
	split(x,rt,l,r);
	int tem=f[l].sz+1;
	rt=merge(l,r);
	cout<<tem-1<<endl;
	return tem-1;
}
int get(int& sd, int lst, const int m) {
	sd = sd * 17 + lst;
	return sd % m + 1;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n>>sd;
		rt=cnt=0;
		for(int i=1;i<=m;i++)
			a[i].ra=a[i].rb=0,ins(a[i]);
		int x,y;
		for(int i=1;i<=n;i++){
			x=get(sd,lst,m);
			y=get(sd,lst,m);
			del(a[x]);
			a[x].ra++,a[x].rb+=y;
			ins(a[x]);
			lst=ask(a[x]);
		}
	}
	return 0;
}
