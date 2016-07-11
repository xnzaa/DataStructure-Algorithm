#include<iostream>
#include<vector>
#include<algorithm>//vector 相关操作函数

using namespace std;

void TestVector(int length)
{
	vector<int> v1(1,2);
	vector<vector<int> > vv;
	vector<int> v;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<v.size()<<endl;//已有元素数量
		v.push_back(50-i);
		cout<<"capacity: "<<v.capacity()<<endl;//最大可容纳元素的数量，采用翻倍的策略进行扩容
	}

	sort(v.begin(),v.end());//排序
	reverse(v.begin(),v.end());//倒置
	v[length-1]=12;

	for(vector<int>::iterator it=v.begin();it<v.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<find(v.begin(),v.end(),10)-v.begin()<<endl;//寻找元素
}