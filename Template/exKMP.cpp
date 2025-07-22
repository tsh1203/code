#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e7+5;
char s[N],ss[N],c[N*2]; 
int z[2*N],p[N];   
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    scanf("%s%s",s+1,ss+1);
    int n=strlen(s+1),m=strlen(ss+1);
    
    z[1]=m;
    int l=0,r=0;
    for(int i=2;i<=m;i++){
        if(i>r){
            l=r=i;
            while(r<=m&&ss[r]==ss[r-l+1])
                r++;
            z[i]=r-l;
            r--;
        } 
        else{
            int k=i-l+1;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<=m&&ss[r]==ss[r-l+1])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    int zz=0;
    for(int i=1;i<=m;i++)
        zz^=(i*(z[i]+1));
    printf("%lld\n",zz);
    
    int cl=m+n+1;
    for(int i=1;i<=m;i++) 
        c[i]=ss[i];
    c[m+1]='#';  
    for(int i=1;i<=n;i++)
        c[m+1+i]=s[i];
    
    memset(z,0,sizeof(z));
    z[1]=cl;
    l=0,r=0;
    for(int i=2;i<=cl;i++){
        if(i>r){
            l=r=i;
            while(r<=cl&&c[r]==c[r-l+1])
                r++;
            z[i]=r-l;
            r--;
        } 
        else{
            int k=i-l+1;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<=cl&&c[r]==c[r-l+1])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    
    int pp=0;
    for(int i=1;i<=n;i++)
        pp^=(i*(z[m+1+i]+1));
    printf("%lld",pp);
    
    return 0;
}
