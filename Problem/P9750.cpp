#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define gcd __gcd
using namespace std;
int t,m;
int a,b,c;
int getk(int &dt){
	int k=1;
	if(dt==0)return 0;
	for(int i=2;i<=sqrt(dt);i++){
		while(dt%(i*i)==0){
			k*=i;
			dt/=i*i;
		}
	}
	return k;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		int dt=b*b-4*a*c;
		if(dt<0){
			cout<<"NO"<<endl;
			continue;
		}
		if(a<0)a=-a,b=-b;
		int k=getk(dt),o1=-b,o2=2*a,f1=0,f2=0;
//		cout<<dt<<" "<<k<<" "<<o1<<" "<<o2<<endl; 
		if(dt==1)o1+=k;
//		cout<<dt<<" "<<k<<" "<<o1<<" "<<o2<<endl; 
		int g=gcd(o1,o2);
		o1/=g,o2/=g;
		if(o2<0)o1=-o1,o2=-o2; 
		if(o1){
			if(o2!=1)cout<<o1<<"/"<<o2;
			else cout<<o1;
			f1=1;
		}
		if(dt!=1&&dt!=0){
			f2=1;
			if(f1)cout<<"+";
			int o3=2*a,g2=gcd(k,o3);
			k/=g2,o3/=g2;
			if(k!=1)cout<<k<<"*";
			cout<<"sqrt("<<dt<<")";
			if(o3!=1)cout<<"/"<<o3;
		}
		if(!f1&&!f2)cout<<0;
		cout<<endl;
	}
	return 0;
}
//-b/2a
