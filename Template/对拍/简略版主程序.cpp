#include<bits/stdc++.h> 
using namespace std; 
int cnt; 
int main() 
{ 
	system("@echo off"); 
	system("cd C:\\Users\\Administrator\\Desktop");//填入文件目录
	system("g++ -O3 -o std.exe  std.cpp");//原程序  
	system("g++ -O3 -o baoli.exe  baoli.cpp");//暴力
	system("g++ -O3 -o data.exe  data.cpp");//数据生成器
	while (1) 
	{ 
		system("data.exe  > in.txt");  //生成输入
		system("baoli.exe  < in.txt  > baoli.txt");  
		system("std.exe  < in.txt  > std.txt");  
		if (system("fc std.txt  baoli.txt")) 
			break; 
	} 
	return 0; 
} 
