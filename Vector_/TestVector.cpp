#include<iostream>
#include<vector>
#include<algorithm>//vector ��ز�������

using namespace std;

void TestVector(int length)
{
	vector<int> v1(1,2);
	vector<vector<int> > vv;
	vector<int> v;
	
	for(int i=0;i<length;i++)
	{
		cout<<"size: "<<v.size()<<endl;//����Ԫ������
		v.push_back(50-i);
		cout<<"capacity: "<<v.capacity()<<endl;//��������Ԫ�ص����������÷����Ĳ��Խ�������
	}

	sort(v.begin(),v.end());//����
	reverse(v.begin(),v.end());//����
	v[length-1]=12;

	for(vector<int>::iterator it=v.begin();it<v.end();it++)
	{
		cout<<*it<<endl;
	}	
	cout<<"location: "<<find(v.begin(),v.end(),10)-v.begin()<<endl;//Ѱ��Ԫ��
}