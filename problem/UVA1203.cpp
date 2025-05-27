#include <bits/stdc++.h>
using namespace std;
int k;
struct no
{
	int id,p,ti;
}h;
bool operator < (const no &a,const no &b)
{
	if(a.ti!=b.ti)return a.ti>b.ti; 
	return a.id>b.id;
}
priority_queue<no>q; 
int main()
{
	while(1)
	{
		string s;
		int id,p;
		cin>>s;
		if(s=="#")break;
		cin>>id>>p;
		q.push({id,p,p});
	}
	cin>>k;
	while(k--)
	{
		h=q.top(); 
		q.pop();
		cout<<h.id<<endl;
		q.push({h.id,h.p,h.ti+h.p});
	}
	return 0;
}
