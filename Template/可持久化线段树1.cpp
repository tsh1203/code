#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define mid ((L+R)>>1)
using namespace std;
const int N=1000006,M=1000006;
struct no
{
	no *l,*r;
	int v;
}tr[M<<5];

no *rt[M];
int a[N];
int n,m,cur=-1;
no *neww()
{
	++cur;
	tr[cur].l=tr[cur].r=tr;
	tr[cur].v=1e9+10;
	return tr+cur;
}

no *pushup(no *past,int L,int R,int x,int v)
{
	no *node=neww();
	(*node)=(*past);
	if(L==R)node->v=v;
	else{
		if(x<=mid)node->l=pushup(past->l,L,mid,x,v);
		else node->r=pushup(past->r,mid+1,R,x,v);
	}
	return node;
}

int query(no *node,int L,int R,int x)
{
	if(L==R)return node->v;
	if(x<=mid)return query(node->l,L,mid,x);
	else return query(node->r,mid+1,R,x);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	rt[0]=neww();
	for(int i=1;i<=m;i++)
	{
		int v,op,x,y;
		cin>>v>>op>>x;
		if(op==1){
			cin>>y;
			rt[i]=pushup(rt[v],1,n,x,y);
		}
		else{
			rt[i]=rt[v];
			int ans=query(rt[i],1,n,x);
			if(ans>1e9+5)ans=a[x];
			cout<<ans<<endl;
		}
	}
	return 0;
}

