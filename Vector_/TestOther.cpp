#include<iostream>
#pragma warning(disable:4786)
//#include<array> //C++11中才有

#include<set>
#include<map>


using namespace std;

const int length2=5;

void TestOther(int length)
{
	int *a1 = new int[length2];
	int a2[]={1,2,3,4,5};
	int a3[length2];//C++可以使用const常量定义数组
//	array<int,5> arr= new arrar[length];
	for(int i=0;i<length;i++)
	{
		cout<<a2[i]<<endl;
	}
}

void TestSet()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(0);
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
	s.insert(1);
	cout<<"size: "<<s.size()<<endl;
	s.erase(1);
	if((it = s.find(2)) != s.end())
    {
         cout<<*it<<endl;
    }

	multiset<int> s2;
	s2.insert(1);
	s2.insert(1);
	cout<<s2.size()<<endl;
	for(multiset<int>::iterator it2=s2.begin();it2!=s2.end();it2++)
	{
		cout<<*it2<<endl;
	}
//	cout<<s.find(2)-s.begin()<<endl;
}

void TestMap()
{
	//VC6.0 对map的支持不是很好，所以下面的代码注释掉了，但是已经在g++上调试通过
	/*
	map<string,int> m;
	m.insert(pair<string,int>("111",1));
	m.insert(map<string,int>::value_type("222",2));
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
	{
	    cout<<it->first<<" "<<it->second<<endl;
	}
	m["333"]=3;
	int a=m["444"];
	cout<<"a:"<<a<<endl;
	
	multimap<string,int> mm;
	//mm不支持mm["111"]=4;
	mm.insert(pair<string,int>("111",1));
	mm.insert(pair<string,int>("111",2));
	mm.insert(pair<string,int>("111",3));
	
	for(map<string,int>::iterator it=mm.begin();it!=mm.end();it++)
	{
	    cout<<"mm"<<it->first<<" "<<it->second<<endl;
	}
	*/
}
