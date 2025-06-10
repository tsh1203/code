#include<bits/stdc++.h>
using namespace std;
int main()
{
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	cout<<rand()<<" "<<rand();
	return 0;
}

