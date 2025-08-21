#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000006;
int n;
int a[N],b[N],c[N];
int ans,len;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		c[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i==1)len=1;
		else{
			if(c[a[i-1]]<c[a[i]])len++;
			else len=1;
		}
		ans+=len;
	}
	cout<<ans;
	return 0;
}
