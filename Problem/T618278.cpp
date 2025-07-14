#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std; 
signed main()
{ 
	int x; 
	cin>>x; 
	int h=x/60,m=x%60;
	cout<<"|"<<h/10<<"|"<<h%10<<"|:|"<<m/10<<"|"<<m%10<<"|";
	return 0; 
} 
