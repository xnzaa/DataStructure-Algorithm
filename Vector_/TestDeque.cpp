#include<iostream>
#include<deque>
#include<algorithm>//��ز�������

using namespace std;

void TestDeque(int length)
{
	deque<int> d1(2,20);
//	deque<deque<int> > ll;//��֧�ֶ�ά����
	deque<int> d;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<d.size()<<endl;//����Ԫ������
		d.push_front(50-i);
//		d.push_back(50-i);//֧��ǰ��ͺ��
	}

	sort(d.begin(),d.end());//�ṩ��׼�����㷨
	reverse(d.begin(),d.end());//����

//	d.sort();
//	d.merge(d1,greater<int>());//�ϲ���������ʹ֮Ĭ������

	for(deque<int>::iterator it=d.begin();it!=d.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<(find(d.begin(),d.end(),49)-d.begin())<<endl;//Ѱ��Ԫ��
}
