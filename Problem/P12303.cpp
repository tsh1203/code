#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
const int N=1e3+3,M=1e2+2;
double sum;
double n,m;
double a[N][M];
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			double x;
			cin>>x;
			sum+=x;
		}
	}
	printf("%.9lf",1.0*sum/n/m);
	return 0;
}
