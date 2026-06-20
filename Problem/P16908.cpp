#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=1e5+5;
int T,c,n;
int a[N];
signed main(){
	FIO
	cin>>T>>c;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			string mo=to_string(i);
			int l=mo.size();
			for(int da=1;da<=a[i];da++){
				int tot=l+da;
				int h=(tot+1)>>1;
				if(l>=h){
					string t=mo.substr(0,h),r=t;
					reverse(r.begin(),r.end());
					if(tot&1)t+=r.substr(1);
					else t+=r;
					if(t.substr(0,l)==mo&&t[l]!='0')ans++;
				}
				else{
					int m=tot-2*l,w=9,f=((m+1)>>1)-1;
					while(f--)w*=10;
					ans+=w;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
