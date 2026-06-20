#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no{
	int f,o,e;
};
int T,n,x;
int dg(string s){
	int an=0;
	for(int i=0;i<s.size();i++)an=an*10+s[i]-'0';
	return an;
}
void rd(no &x){
	string e1,o,e2;
	cin>>e1>>o>>e2;
	if(e1=="x")x.f=1,x.e=dg(e2);
	else x.f=2,x.e=dg(e1);
	if(o=="+")x.o=1;
	else if(o=="-")x.o=2;
	else if(o=="*")x.o=3;
	else x.o=4;
}
int fun(int x,no d){
	if(d.f==1){
		if(d.o==1)x+=d.e;
		if(d.o==2)x-=d.e;
		if(d.o==3)x*=d.e;
		if(d.o==4)x/=d.e;
	}
	else{
		if(d.o==1)x=x+d.e;
		if(d.o==2)x=d.e-x;
		if(d.o==3)x=d.e*x;
		if(d.o==4)x=d.e/x;
	}
	return x;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		int mx=x,mi=x;
		for(int i=1;i<=n;i++){
			no x,y;
			rd(x);rd(y);
			int r1=fun(mx,x),r2=fun(mx,y),r3=fun(mi,x),r4=fun(mi,y);
			mx=max(r1,max(r2,max(r3,r4)));
			mi=min(r1,min(r2,min(r3,r4)));
		}
		cout<<mx<<endl;
	}
	return 0;
}
