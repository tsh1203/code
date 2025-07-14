#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1000006;
const double alpha=0.75;
int id,rt,lc[N],rc[N],tot[N],ta;
int val[N],cnt[N],sz[N],tmp[N],cntt;

void push_up(int x){
	tot[x]=1+tot[lc[x]]+tot[rc[x]];
	sz[x]=cnt[x]+sz[lc[x]]+sz[rc[x]];
}
void flatten(int x){
	if(!x)return;
	flatten(lc[x]);
	if(cnt[x])tmp[cntt++]=x;
	flatten(rc[x]);
}
int build(int ll,int rr){
	if(ll>rr)return 0;
	int mm=(ll+rr)/2;
	int x=tmp[mm];
	lc[x]=build(ll,mm-1);
	rc[x]=build(mm+1,rr);
	push_up(x);
	return x;
}
void rebuild(int &x){
	cntt=0;
	flatten(x);
	x=build(0,cntt-1);
}
bool add(int &x,int v,int dep){
	bool check=false;
	if(!x){
		x=++id;
		val[x]=v;
		check=dep>log(tot[rt]+1)/log(1/alpha);
	}
	if(val[x]==v){
		if(!cnt[x])++ta;
		++cnt[x];
	}
	else if(v<val[x]){
		check=add(lc[x],v,dep+1);
	}
	else{
		check=add(rc[x],v,dep+1);
	}
	push_up(x);
	if(check&&(tot[lc[x]]>alpha*tot[x]||tot[rc[x]]>alpha*tot[x])){
		rebuild(x);
		return false;
	}
	return check;
}
void add(int v){
	add(rt,v,0);
}
bool del(int x,int v){
	if(!x)return false;
	bool succ=true;
	if(v<val[x]){
		succ=del(lc[x],v);
	}
	else if(v>val[x]){
		succ=del(rc[x],v);
	}
	else if(cnt[x]){
		--cnt[x];
		if(!cnt[x])--ta;
	}
	else{
		succ=false;
	}
	push_up(x);
	return succ;
}
bool del(int v){
	bool succ=del(rt,v);
	if(!ta){
		rt=0;
	}else if(succ&&ta<tot[rt]*alpha){
		rebuild(rt);
	}
	return succ;
}
int ranks(int v){
	int res=0;
	int x=rt;
	while(x&&val[x]!=v){
		if(v<val[x]){
			x=lc[x];
		}else {
			res+=sz[lc[x]]+cnt[x];
			x=rc[x];
		}
	}
	return res+sz[lc[x]]+1;
}
int kth(int k){
	if(k<=0||sz[rt]<k)return -1;
	int x=rt;
	while(1){
		if(k<=sz[lc[x]]){
			x=lc[x];
		}
		else if(k<=sz[lc[x]]+cnt[x]){
			return val[x];
		}
		else{
			k-=sz[lc[x]]+cnt[x];
			x=rc[x];
		}
	}
	return -1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	while(n--)
	{
		int op,x;
		cin>>op>>x;
		switch(op)
		{
		case 1:
			add(x);
			break;
		case 2:
			del(x);
			break;
		case 3:
			cout<<ranks(x)<<endl;
			break;
		case 4:
			cout<<kth(x)<<endl;
			break;
		case 5:
			cout<<kth(ranks(x)-1)<<endl;
			break;
		case 6:
			cout<<kth(ranks(x+1))<<endl;
			break;
		}
	}
	return 0;
}
