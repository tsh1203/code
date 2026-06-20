#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
const int N=3003;
string s,t;
int n,m;
int d[5][5];
int A,B;
int f[N][N][3];//都没有，A，B
int cd(char c){
	if(c=='A')return 1;
	else if(c=='T')return 2;
	else if(c=='G')return 3;
	else return 4;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	cin>>s>>t;
	n=s.length(),m=t.length();
	for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)cin>>d[i][j];
	cin>>A>>B;
	for(int i=1;i<=n;i++){
		f[i][0][1]=f[i][0][0]=-1e18;
		f[i][0][2]=-A-B*(i-1);
	}
	for(int i=1;i<=m;i++){
		f[0][i][2]=f[0][i][0]=-1e18;
		f[0][i][1]=-A-B*(i-1);
	}
	f[0][0][1]=f[0][0][2]=-1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i&&j)f[i][j][0]=max({f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j-1][2]})+d[cd(s[i-1])][cd(t[j-1])];
			if(j)f[i][j][1]=max({f[i][j-1][0]-A,f[i][j-1][2]-A,f[i][j-1][1]-B});
			if(i)f[i][j][2]=max({f[i-1][j][0]-A,f[i-1][j][1]-A,f[i-1][j][2]-B});
		}
	}
	cout<<max({f[n][m][0],f[n][m][1],f[n][m][2]});
	return 0;
}
