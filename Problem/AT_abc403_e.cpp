#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
const int N=0235*1e4+5;
int ch[N][26];
int b[N],tot,sz,cnt[N];
int ci(char d){
	return d-'a';
} 
void ins1(string s){
	int l=s.length(),r=0;
	bool f=true;
	for(int i=0;i<l;i++){
		int d=ci(s[i]);
		if(!ch[r][d])ch[r][d]=++tot;
		r=ch[r][d];
		if(b[r])f=false;
	}
	b[r]=1;
	if(f){
		int y;
		cnt[y]-=cnt[r];
		for(int i=0;i<l;i++){
			int d=ci(s[i]);
			y=ch[y][d];
			cnt[y]-=cnt[r];
		}
	}
}
void ins2(string s){
	int l=s.length(),r=0;
	bool f=true;
	for(int i=0;i<l;i++){
		int d=ci(s[i]);
		if(!ch[r][d])ch[r][d]=++tot;
		r=ch[r][d];
		if(b[r])f=false;
	}
	if(f){
		r=0;
		cnt[r]++;
		for(int i=0;i<l;i++){
			int d=ci(s[i]);
			r=ch[r][d];
			cnt[r]++;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		int op;
		string s;
		cin>>op;
		if(op==1){
			cin>>s;
			ins1(s);
		}
		else{
			cin>>s;
			ins2(s);
		}
		cout<<cnt[0]<<endl;
	}
	return 0;
}
