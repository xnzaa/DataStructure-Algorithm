#include <iostream>
#include <queue>

using namespace std;


class compare
{
public:
	bool operator()(int a,int b)
	{
		return a<b;
	}
};

void TestPriorityQueue()
{
//容器可以是 vector, deque 等数组形，但不能用 list.  比较方式可以为less<T> 或者greater<T>
//STL里面容器默认用的是 vector. 比较方式默认用 operator< 即队头元素最大。
	priority_queue<int, vector<int>, compare > q;
	q.push(1);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		//不用front，使用top
		cout<<q.top()<<endl;
		q.pop();
	}
}