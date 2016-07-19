#include<iostream>
#include<vector>

using namespace std;

const int mode=7;

vector<int> v;

extern void init(vector<int> &);
extern void select_sort(vector<int> &);
extern void heap_sort(vector<int> &v);
extern void insert_sort(vector<int> &);
extern void shell_sort(vector<int> &v);
extern void bubble_sort(vector<int> &v);
extern void sort_print(vector<int> &v,double time);
extern void quick_sort(vector<int> &v);
extern void merge_2_sort(vector<int> &v);
extern void radix_sort(vector<int> &v);

/**
* 运行时间统计：1-100范围共产生10000个整数进行排序(ms)
*	(CPU: 2.4G  RAM:1G  OS:X64)
* 0:4187
* 1:46
* 2:2953
* 3:1734
* 4:6453
* 5:31
* 6:93
* 7:31
*/

int main()
{
	init(v);
	switch(mode)
	{
		case 0:select_sort(v); break;
		case 1:heap_sort(v); break;
		case 2:insert_sort(v); break;
		case 3:shell_sort(v); break;
		case 4:bubble_sort(v); break;
		case 5:quick_sort(v); break;
		case 6:merge_2_sort(v); break;
		case 7:radix_sort(v); break;
		default:sort_print(v,0);break;
	}
	return 0;
}