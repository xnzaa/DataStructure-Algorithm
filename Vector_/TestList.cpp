#include<iostream>
#include<list>
#include<algorithm>//��ز�������

using namespace std;

void TestList(int length)
{

	list<int> l1(2,20);
//	list<list<int> > ll;//��֧�ֶ�ά����
	list<int> l;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<l.size()<<endl;//����Ԫ������
		l.push_front(50-i);
//		l.push_back(50-i);//֧��ǰ��ͺ��
	}

//	sort(l.begin(),l.end());//�Դ������㷨�����ṩ��׼�����㷨
	l.sort();
	reverse(l.begin(),l.end());//����

	l.merge(l1,greater<int>());//�ϲ���������ʹ֮Ĭ������

	for(list<int>::iterator it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<(*find(l.begin(),l.end(),49))<<endl;//Ѱ��Ԫ��
}
