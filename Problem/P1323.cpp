#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
using namespace std;
int k,m,sz,an;
priority_queue<int,vector<int>,greater<int> >q; 
string num;
char ans[1000006];
vector<int>cnt;
void upt(int x){
	string s="";
	while(x)s+=(x%10+'0'),x/=10;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='9')cnt.push_back(sz);
		num+=s[i],++sz;	
	}
	return;
}
signed main(){
	FAST_IO
	cin>>k>>m;
	q.push(1),cnt.push_back(0);
	for(int i=1;i<=k;i++){
		int fr=q.top();
		q.pop();
		upt(fr);
		q.push(2*fr+1); 
		q.push(4*fr+5); 
//		cout<<fr<<endl;
	}
	cout<<num<<endl; 
	for(int i=0;i<sz;i++){
		if(i==0)ans[an]=num[i];
		else{
			while(ans[an]<num[i]&&m){
				m--;
				an--;
				if(an<0)break;
			}
			ans[++an]=num[i];
		}
	}
	for(int i=0;i<=an;i++)cout<<ans[i];
	return 0;
}
