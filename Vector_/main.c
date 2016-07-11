#include<iostream>
#include<vector>

using namespace std;

void main()
{

	vector<int> v(10,1);
	v.push_back(10);
	cout<<v.size()<<endl;

	//for(vector<int>::iterator it=v.begin();it<v.end();it++)
//	{
//		cout<<*it<<endl;
//	}
}