#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FIO ios::sync_with_stdio(false);cin.tie(0);
#define memin(a) memset(a,128,sizeof a);
#define memax(a) memset(a,127,sizeof a);
#define memze(a) memset(a,0,sizeof a);
using namespace std;
const int N=1e4+4;
int n,m,a[N];
signed main(){
	FIO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
