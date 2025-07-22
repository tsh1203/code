#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+6;
int n;
int ans,a[N],v[N];
stack<int>st;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    st.push(0);
    for(int i=1;i<=n;i++){
        while(st.size()&&a[i]<=a[st.top()])
			st.pop();
        if(st.size())
			v[i]=(i-st.top())*a[i];
        st.push(i);
        ans=max(ans,v[i]);
    }
    while(!st.empty())st.pop();
    st.push(n+1);
    for(int i=n;i>0;i--){
        while(st.size()&&a[i]<=a[st.top()])
			st.pop();
        if(st.size())
			v[i]+=(st.top()-i-1)*a[i];
        st.push(i);
        ans=max(ans,v[i]);
    }
    cout<<ans;
    return 0;
}
