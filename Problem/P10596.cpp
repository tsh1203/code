#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int MOD=1000000007;
const int MAX=1000005;
int f[MAX],iF[MAX];
int p(int b,int e){
    int r=1;
    b%=MOD;
    while(e>0){
        if(e%2==1)r=(r*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }
    return r;
}
int pm(int b,int e,int m){
    int r=1;
    b%=m;
    while(e>0){
        if(e%2==1)r=(r*b)%m;
        b=(b*b)%m;
        e/=2;
    }
    return r;
}
void pre(){
    f[0]=1;
    iF[0]=1;
    for(int i=1;i<MAX;++i){
        f[i]=(f[i-1]*i)%MOD;
    }
    iF[MAX-1]=p(f[MAX-1],MOD-2);
    for(int i=MAX-2;i>=1;--i){
        iF[i]=(iF[i+1]*(i+1))%MOD;
    }
}
int C(int n,int k){
    if(k<0||k>n)return 0;
    return(((f[n]*iF[k])%MOD)*iF[n-k])%MOD;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<0<<endl;
        return 0;
    }
    pre();
    int res=0;
    int exp_mod=MOD-1;
    for(int i=0;i<=n-k;++i){
        int term_c=C(n-k,i);
        int exp_p2=pm(2,n-k-i,exp_mod);
        int term_p=p(2,exp_p2);
        int term=(term_c*(term_p-1+MOD))%MOD;
        if(i%2==1)res=(res-term+MOD)%MOD;
        else res=(res+term)%MOD;
    }
    int final_res=(C(n,k)*res)%MOD;
    cout<<final_res;
    return 0;
}
