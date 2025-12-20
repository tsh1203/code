#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=3e5+5;
struct no{
	int x,y,z;
}b[N];
int n,s,r,su,cnt;
int a[N],ans;
void print(int x,int y,int z){
	b[++cnt]={x,y,z};
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s/=n;
	for(int i=1;i<=n;i++)
		a[i]-=s;
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[i]>0){
				print(i,i+1,a[i]);
				a[i+1]+=a[i];
				a[i]=0;
				r=i;
			}
			else if(a[i]==0)r=i;
			else{
				su+=a[i];
			}
		}
		else if(a[i]+s+su>=0){
			a[i]+=su;
			for(int j=i-1;j>r;j--){
				print(j+1,j,-su);
				su-=a[j];
				a[j]=0;
			}
			
			if(a[i]<0)su=a[i],r=i-1;
			else {
				if(a[i]!=0)print(i,i+1,a[i]);
				a[i+1]+=a[i],a[i]=0,r=i;
			}
		}
		else su+=a[i];
	}
	cout<<cnt<<endl;
	return 0;
}
