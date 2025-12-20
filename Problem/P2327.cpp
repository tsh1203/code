#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=11004,MX=1e9;
int n,ans;
int a[N],b[N];
int cnt(int x){
	return (b[x-1]==1)+(b[x]==1)+(b[x+1]==1);
}
int check(int x){
	if(x==0)return 1;
//	if(cnt(x)!=a[x]){
//		cout<<"break at"<<x<<endl;
//	}
	return cnt(x)==a[x];
}
void dfs(int x){
	if(x>n){
		if(cnt(n)==a[n]){
			ans++;
//			for(int i=1;i<=n;i++)
//				cout<<(b[i]==1)<<" ";
//			cout<<endl;
		}
		return;
	}
	if(b[x]==0){
		b[x]=1;
		if(check(x-1))
			dfs(x+1);
		
		b[x]=0;
		if(check(x-1))
			dfs(x+1);
	}
	else if(check(x-1))dfs(x+1);
}
signed main() 
{
    ios::sync_with_stdio(0);	
	cin.tie(0);
	cout.tie(0);
//	freopen("in.txt","r",stdin);
	cin>>n;
	b[0]=b[n+1]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==3){
			if(b[i-1]==-1||b[i]==-1||b[i+1]==-1){
				cout<<0;
				return 0;
			}
			b[i-1]=b[i+1]=b[i]=1;
		}
		if(a[i]==0){
			if(b[i-1]==1||b[i]==1||b[i+1]==1){
				cout<<0;
				return 0;
			}
			b[i-1]=b[i+1]=b[i]=-1;
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}

//1 0 0 0

//1 2 3 2 2 2 2 
//a 1 1 1 a 0 0
//0 0 0 0 1 2 2 

//1 1 0 1
