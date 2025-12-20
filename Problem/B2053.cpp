#include<bits/stdc++.h> 
using namespace std;
int main(){
	double a,b,c;
    cin>>a>>b>>c;
    double dt=b*b-4*a*c;
    if(dt>0){
        double x1=(-b+sqrt(dt))/(2.0*a);
        double x2=(-b-sqrt(dt))/(2.0*a);
        if (x1>x2)swap(x1,x2);
        printf("x1=%.5lf;x2=%.5lf",x1,x2);
    }
	else if(dt==0){
        double x1=(-b+sqrt(dt))/(2.0*a);
        double x2=(-b-sqrt(dt))/(2.0*a);
        printf("x1=x2=%.5lf",x1);
    }
	else{
        cout<<"No answer!";
    }
    return 0;
}
