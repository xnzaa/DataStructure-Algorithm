#include<iostream>
#include<list>
#include<algorithm>//相关操作函数

using namespace std;

void TestList(int length)
{

	list<int> l1(2,20);
//	list<list<int> > ll;//不支持二维数组
	list<int> l;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<l.size()<<endl;//已有元素数量
		l.push_front(50-i);
//		l.push_back(50-i);//支持前插和后插
	}

//	sort(l.begin(),l.end());//自带排序算法，不提供标准排序算法
	l.sort();
	reverse(l.begin(),l.end());//倒置

	l.merge(l1,greater<int>());//合并两个链表并使之默认升序

	for(list<int>::iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<(*find(l.begin(),l.end(),49))<<endl;//寻找元素
}
