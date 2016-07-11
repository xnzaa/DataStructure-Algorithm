#include<iostream>
#include<deque>
#include<algorithm>//相关操作函数

using namespace std;

void TestDeque(int length)
{
	deque<int> d1(2,20);
//	deque<deque<int> > ll;//不支持二维数组
	deque<int> d;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<d.size()<<endl;//已有元素数量
		d.push_front(50-i);
//		d.push_back(50-i);//支持前插和后插
	}

	sort(d.begin(),d.end());//提供标准排序算法
	reverse(d.begin(),d.end());//倒置

//	d.sort();
//	d.merge(d1,greater<int>());//合并两个链表并使之默认升序

	for(deque<int>::iterator it=d.begin();it!=d.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<(find(d.begin(),d.end(),49)-d.begin())<<endl;//寻找元素
}
