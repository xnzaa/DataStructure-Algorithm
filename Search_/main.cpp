#include<iostream>
#include<vector>

using namespace std;

extern int binarySearch(vector<int> &v,int m);
extern void init(vector<int> &v);
extern int fbSearch(vector<int> &v,int m);


int mode=1;
vector<int> v;

void main()
{
	init(v);
	switch(mode)
	{
		case 0:binarySearch(v,9);break;
		case 1:fbSearch(v,2);break;
		default:break;
	}
}
