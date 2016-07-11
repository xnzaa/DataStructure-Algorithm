#include<iostream>
#include<vector>
#include<algorithm>//vector 相关操作函数

using namespace std;


extern void TestVector(int);
extern void TestList(int);
extern void TestDeque(int);
extern void TestOther(int); 
extern void TestSet();
extern void TestMap();


void main()
{
//	TestVector(5);
//	TestList(5);
//	TestDeque(5);
//	TestOther(5);
	TestSet();
}