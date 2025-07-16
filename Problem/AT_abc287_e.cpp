#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e5+5;
int tot,ch[N][70],cnt[N];
int pos[N];
string s[N];
int ci(char x){
		return x-'a';
} 
void insert(string s){
	int r=0,l=s.length();
	for(int i=0;i<l;i++){
		int d=ci(s[i]);
		if(!ch[r][d])
			ch[r][d]=++tot;
		else pos[ch[r][d]]++;
		r=ch[r][d];
	}
	
}
int find(string s){
	int r=0,l=s.length();
	int ans=0;
	for(int i=0;i<l;i++){
		int c=ci(s[i]);
		if(pos[ch[r][c]])ans++;
		else break;
		r=ch[r][c];
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		insert(s[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<find(s[i])<<endl;
	}
	return 0;
}
