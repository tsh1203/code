#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

struct Node{
	int l,r,val,key,size;
	bool rev;
}fhq[N];
int cnt,root[2];
mt19937 rnd(time(0));

inline int newNode(int val){
	fhq[++cnt]={0,0,val,(int)rnd(),1,false};
	return cnt;
}

inline void pushdown(int x){
	if(!fhq[x].rev) return;
	swap(fhq[x].l,fhq[x].r);
	if(fhq[x].l) fhq[fhq[x].l].rev^=1;
	if(fhq[x].r) fhq[fhq[x].r].rev^=1;
	fhq[x].rev=false;
}

inline void update(int x){
	fhq[x].size=fhq[fhq[x].l].size+fhq[fhq[x].r].size+1;
}

void split(int now,int k,int &x,int &y){
	if(!now){x=y=0;return;}
	pushdown(now);
	if(fhq[fhq[now].l].size<k){
		x=now;
		split(fhq[now].r,k-fhq[fhq[now].l].size-1,fhq[now].r,y);
	}else{
		y=now;
		split(fhq[now].l,k,x,fhq[now].l);
	}
	update(now);
}

int merge(int x,int y){
	if(!x||!y) return x|y;
	pushdown(x);pushdown(y);
	if(fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		update(x);
		return x;
	}else{
		fhq[y].l=merge(x,fhq[y].l);
		update(y);
		return y;
	}
}

void reverse(int id,int l,int r){
	int x,y,z;
	split(root[id],l-1,x,y);
	split(y,r-l+1,y,z);
	fhq[y].rev^=1;
	root[id]=merge(merge(x,y),z);
}

void getOrder(int now,vector<int>&v){
	stack<int> s;
	while(now||!s.empty()){
		while(now){
			s.push(now);
			pushdown(now);
			now=fhq[now].l;
		}
		now=s.top();s.pop();
		v.push_back(fhq[now].val);
		now=fhq[now].r;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int H,W; cin>>H>>W;
	vector<string> grid(H);
	for(auto &row:grid) cin>>row;
	
	for(int i=1;i<=H;i++) root[0]=merge(root[0],newNode(i));
	for(int i=1;i<=W;i++) root[1]=merge(root[1],newNode(i));
	
	int Q; cin>>Q;
	while(Q--){
		int a,b; cin>>a>>b;
		reverse(0,1,a);
		reverse(0,a+1,H);
		reverse(1,1,b);
		reverse(1,b+1,W);
	}
	
	vector<int> rowOrder,colOrder;
	getOrder(root[0],rowOrder);
	getOrder(root[1],colOrder);
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++)
			cout<<grid[rowOrder[i]-1][colOrder[j]-1];
		cout<<'\n';
	}
	return 0;
}
