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
//���������� vector, deque �������Σ��������� list.  �ȽϷ�ʽ����Ϊless<T> ����greater<T>
//STL��������Ĭ���õ��� vector. �ȽϷ�ʽĬ���� operator< ����ͷԪ�����
	priority_queue<int, vector<int>, compare > q;
	q.push(1);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		//����front��ʹ��top
		cout<<q.top()<<endl;
		q.pop();
	}
}