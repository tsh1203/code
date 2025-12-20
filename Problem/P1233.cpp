#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
struct no{
	int l,w;
}a[N];
int n;
int f[N];
int ans=-1e9;
bool cmp(no x,no y){
	if(x.l!=y.l)return x.l>y.l;
	return x.w>y.w;
} 
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j].w<a[i].w){
				f[i]=max(f[i],f[j]+1);
			}
		} 
		ans=max(ans,f[i]);
	}
	cout<<ans+1;
	return 0;
} 
