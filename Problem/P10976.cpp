#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n1,n2,ans,l1,l2;
string s1,s2,str1;
int main(){
	while(cin>>s2>>n2>>s1>>n1){
		ans=0;
		str1="";
		for(int i=1;i<=n1;i++)str1+=s1;
		l1=str1.size(),l2=s2.size();
		for(int i=0,j=0;i<l1;i++){
			if(str1[i]==s2[j]){
				if(j==l2-1){ans++,j=0;}
				else j++;
			}
		}
		cout<<ans/n2<<endl;
	}
	return 0;
}
