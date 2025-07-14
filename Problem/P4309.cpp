#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
int a[N],ans[N];
vector<int>v;
int lb(int x){return x&-x;}
void upd(int x,int v){
	while(x<=n){
		a[x]=max(a[x],v);
		x+=lb(x);
	} 
}
int qry(int x){
	int t=0;
	while(x){
		t=max(a[x],t);
		x-=lb(x);
	} 
	return t;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		v.insert(t+v.begin(),i);
	}
	for(int i=0;i<n;i++){
		int t=v[i];
		ans[t]=qry(t)+1;
		upd(t,ans[t]);
	}
	for(int i=1;i<=n;i++){
		ans[i]=max(ans[i],ans[i-1]);
		cout<<ans[i]<<endl;
	}
	return 0;
}
