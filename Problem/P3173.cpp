#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct no{
	int l,w;
}a[N];
int n,m;
int ans=0,x=1,y=1;
bool cmp(no x,no y){
	if(x.l!=y.l)return x.l>y.l;
	else return x.w>y.w;
} 
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n+m-2;i++){
		cin>>a[i].l;
		if(i<n)a[i].w=1;
		else a[i].w=2;
	}
	sort(a+1,a+n+m-1,cmp);
	for(int i=1;i<=n+m-2;i++){
		if(a[i].w==1){
			ans+=a[i].l*y;
			x++;
		}
		else{
			ans+=a[i].l*x;
			y++;
		}
	}
	cout<<ans;
	return 0;
} 
