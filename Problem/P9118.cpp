#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
using namespace std;
int n,k,x;
map<int,bool>f;
int oiiaio(){//k>=3
	int ans=0;
	for(int i=2;i*i*i<=n;i++){
		int num=i*i,m=2;
		while(num<=n/i){
			num*=i,m++;
			if(m<k)continue;
			if(f[num])continue;
			if((int)sqrtl(num)*(int)sqrtl(num)==num)x++;
			f[num]=1,ans++;
		}
	}
	return ans;
}
signed main(){
	FAST_IO
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	int ans=oiiaio();
	if(k==2)cout<<ans+(int)sqrtl(n)-x;
	if(k>2)cout<<ans+1;
	return 0;
}	
