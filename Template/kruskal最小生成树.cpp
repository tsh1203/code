#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no{
	int x,y,z;
}e[2000006];
int n,m,cnt;
int f[100005];
int res;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(no a,no b){
	return a.z<b.z;
}
void kruskal(){
	
	for(int i=1;i<=m;i++){
		int ra=find(e[i].x);
		int rb=find(e[i].y);
		if(ra==rb)continue;
		res+=e[i].z;
		f[ra]=rb;
		cnt++;
		if(cnt==n-1)break;
	}
} 
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+m+1,cmp);
	kruskal();
	if(cnt!=n-1)cout<<"orz";
	else cout<<res;
	return 0;
}
