#include<bits/stdc++.h> 
using namespace std; 
int cnt; 
int main() 
{ 
	system("@echo off"); 
	system("cd C:\\Users\\Administrator\\Desktop");//填入文件目录
	
	if (system("g++ -O3 -o std.exe   std.cpp") != 0){ 
		cerr<<"Error: Compilation of std.cpp  failed."<< endl; 
		return 1; 
	} 
	cout<<"std.cpp  Running completed\n"; 
	
	// 编译暴力程序 
	if (system("g++ -O3 -o baoli.exe   baoli.cpp") != 0){ 
		cerr<<"Error: Compilation of baoli.cpp  failed."<<endl; 
		return 1; 
	} 
	cout<<"baoli.cpp  Running completed\n"; 
	
	// 编译数据生成器 
	if (system("g++ -O3 -o data.exe   data.cpp") != 0){ 
		cerr<<"Error: Compilation of data.cpp  failed."<<endl; 
		return 1; 
	} 
	cout<<"data.cpp Running completed\n"; 
	
	while (1) 
	{ 
		system("data.exe  > in.txt");  //生成输入
		system("baoli.exe  < in.txt  > baoli.txt");  
		system("std.exe  < in.txt  > std.txt");  
		if (system("fc std.txt  baoli.txt  > nul")) 
		{
			cout<<"Find a difference in the output "<<cnt;
			break; 
		}
		++cnt;
		cout<<"There is no difference in the output "<<cnt<<endl;
	} 
	return 0; 
} 
