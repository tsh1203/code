#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+6;
string s,st[N];
int cnt=1;
char zh(char c){
	if(c>='A'&&c<='Z')return c-('A'-'a');
	return c;
}
bool cd(string s){
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')))
			return 0;
	}
	return 1;
}
bool pd(string s,string t,int op){
	if(op)if(s.size()!=t.size())return 0;
	int l=min(s.size(),t.size());
	for(int i=0;i<l;i++)
		if(zh(s[i])!=zh(t[i]))
			return 0;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='.')++cnt;
		else st[cnt]+=s[i];
	}
	if(cnt<3)return 0;
	bool f1=0;
	int sz=0;
	for(int i=1;i<=cnt;i++){
		if(st[i]==""||!cd(st[i]))return 0;
		if(i==1){
			sz+=st[i].size()+1;
			continue;
		}
		if(f1==0){
			if(pd(st[i],"edu",1))
				f1=1;
		}
		else{
			if(pd(st[i],"cn",0)){
				cout<<sz+2<<" ";
			}
			f1=0;
		}
		sz+=st[i].size()+1;
	}
	return 0;
}
