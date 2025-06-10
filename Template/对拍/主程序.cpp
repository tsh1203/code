#include<bits/stdc++.h> 
using namespace std; 
int cnt; 
int main() 
{ 
	system("@echo off"); 
	system("cd C:\\Users\\Administrator\\Desktop");//填入文件目录
	
	system("g++ -o std.exe  std.cpp");//原程序  
	cout<<"std.cpp Running completed\n";
	
	system("g++ -o baoli.exe  baoli.cpp");//暴力
	cout<<"baoli.cpp Running completed\n";
	
	system("g++ -o data.exe  data.cpp");//数据生成器
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
