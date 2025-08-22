#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=102;
int t,n,m;
int dx[10]={0,0,1,-1},dy[10]={1,-1,0,0};
int a[N][N],b[N][N];
bool ck(int x,int y){
	return x>0&&y>0&&x<=n&&y<=m;
}
bool check(int x,int y){
	int sum=0;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(!ck(xx,yy)||(ck(xx,yy)&&!a[xx][yy]))
			sum++;
	}
	return sum>=3;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(ck(xx,yy)&&a[xx][yy]&&!b[xx][yy]){
			b[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}

void solve(){
	memset(b,0,sizeof b);
	cin>>n>>m;
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
//			if(c=='G'){
//				a[i][j]=1;
//				tot++;
//			}
			a[i][j]=(c=='G');
			tot+=a[i][j];
			
		}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!b[i][j]&&a[i][j]){
				sum++;
				b[i][j]=1;
				dfs(i,j);
			}
		}
	}
	if(sum>=2){
		cout<<0<<endl;
		return;
	}
	if(sum<2&&tot<=2){
		cout<<-1<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(check(i,j)&&a[i][j]){
				cout<<1<<endl;
				return;
			}
		}
	}
	cout<<2<<endl;
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

