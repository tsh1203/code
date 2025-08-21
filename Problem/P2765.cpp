#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[102][102];
bool ck(int x){
	int sq=sqrt(x);
	return sq*sq==x;
}
signed main(){
	cin>>n;
	m=(n*(n+2)+(n&1)-2)/2;
	cout<<m<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x=a[j][a[j][0]];
			if(!x||ck(x+i)){
				a[j][++a[j][0]]=i;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i][0];j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
