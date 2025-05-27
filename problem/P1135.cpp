#include <bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int id;
};
int n,a,b;
int arr[205];
bool f[205];
void bfs(){
	queue<node> q;
	q.push((node){a,0});
	while(!q.empty()){
		if(q.front().num==b){
			cout<<q.front().id;
			return ;
		}
		int x1=q.front().num+arr[q.front().num];
		int x2=q.front().num-arr[q.front().num];
		if(x1>=1 && x1<=n && !f[x1]){
			f[x1]=true;
			q.push((node){x1,q.front().id+1});
		}
		if(x2>=1 && x2<=n && !f[x2]){
			f[x2]=true;
			q.push((node){x2,q.front().id+1});
		}
		q.pop();
	}
	cout<<"-1";
	return ;
}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int ans=0;
	bfs();
	return 0;
}
