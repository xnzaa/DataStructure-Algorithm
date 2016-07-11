#include <iostream>
#include <queue>

using namespace std;

void TestQueue()
{
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
}