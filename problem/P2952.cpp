#include<bits/stdc++.h>
using namespace std;
int n;
int v;
int num,gnum;
deque<int>q;
signed main()
{
	cin>>n;
	int x=1;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		if(a=='A')
		{
			if(b=='L')q.push_front(x++);
			if(b=='R')q.push_back(x++);
		}
		else
		{
			cin>>v;
			if(b=='L')for(int i=1;i<=v;i++)q.pop_front();
			if(b=='R')for(int i=1;i<=v;i++)q.pop_back();
		}
	}
	while(q.size())
	{
		cout<<q.front()<<endl;
		q.pop_front();
	}
	return 0;
}
