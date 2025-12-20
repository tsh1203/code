#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=102;
const int mod=9999973;
int n,m;
int dp[N][N][N];
int fun(int x){
    return x*(x-1)/2;
}
signed main(){
    cin>>n>>m;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=m;j++){
    		for(int k=0;j+k<=m;k++){
    			if(dp[i-1][j][k]){
			        dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
			        if(m-j-k>=1)dp[i][j+1][k]=(dp[i][j+1][k]+dp[i-1][j][k]*(m-j-k))%mod;
			        if(j>=1)dp[i][j-1][k+1]=(dp[i][j-1][k+1]+dp[i-1][j][k]*j)%mod;
			        if(m-j-k>=2)dp[i][j+2][k]=(dp[i][j+2][k]+dp[i-1][j][k]*fun(m-j-k))%mod;
			        if(m-j-k>=1&&j>=1)dp[i][j][k+1]=(dp[i][j][k+1]+dp[i-1][j][k]*(m-j-k)*j)%mod;
			        if(j>=2)dp[i][j-2][k+2]=(dp[i][j-2][k+2]+dp[i-1][j][k]*fun(j))%mod;
				}
			}
   		}
	}
    int ans=0;
    for(int i=0;i<=m;i++)
    for(int j=0;i+j<=m;j++){
        ans=(ans+dp[n][i][j])%mod;
    }
    cout<<ans; 
    return 0;
}

