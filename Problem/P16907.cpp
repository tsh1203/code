#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=1e3+3;
int T,n,m;
int a[N],s[N];
signed main(){
	FIO
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>s[i];
		for(int i=1;i<=n;i++){
			int b=a[i]*3/10;
			if(b>=m){
				cout<<"inf ";
			}
			else{
				int ans=(250-s[i])*(a[i]/250);
				if(ans<m)cout<<0<<" ";
				else cout<<(ans-m)/50+1<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
