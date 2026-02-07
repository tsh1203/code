#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define memset mem
using namespace std;
const int mod=998244353;
int ksm(int a,int b){
	int an=1,t=a;
	while(b){
		if(b&1)an=an*t%mod;
		t=t*t%mod;
		b>>=1;
	}
	return an;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int x=ksm(2,k)-1;
	cout<<ksm(x,n);
	return 0;
}
