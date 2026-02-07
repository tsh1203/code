#include<bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
#define mem memset
#define pii pair<int,int>
using namespace std;
const int N=1e6+6; 
int k,n,a[N];
deque<int>que; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(que.size()&&a[que.back()]<=a[i])que.pop_back();
		while(que.size()&&i>=que.front()+k)que.pop_front();
		que.push_back(i);
		if(i>=k)cout<<que.size()<<endl; 
	}
	return 0;
}
//5 4 6
