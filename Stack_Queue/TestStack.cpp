#include<iostream>
#include<stack>

using namespace std;

void TestStack()
{
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(4);

	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}
