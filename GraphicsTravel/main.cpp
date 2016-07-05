#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include "Graphics.h"

//0xcccc 烫
//0xcdcd 屯

using namespace std;

void main()
{

	vector<int> v(5,-5);
	for(vector<int>::iterator ite=v.begin();ite<v.end();ite++)
	{
		cout<<"Test: "<<*ite<<endl;
	}
	Grap<int> grap(3);
	grap.init();
//	grap.PFS_travel();
//	grap.prime(0);
//	grap.dijkstra(0);
	grap.Tsort(0);
//	grap.TsortQueue();
}



//2种方法：
//1：入度为0点输出拓扑排序，队列
//2：出度为0点输出，为拓扑排序的逆过程，仿照DFS，栈逆序
