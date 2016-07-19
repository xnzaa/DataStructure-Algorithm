#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &v,int m,bool find)
{
	if(find)
		cout<<"找到结果为: "<<m<<endl;
	else
		cout<<"未搜索到结果"<<endl;
}

void init(vector<int> &v)
{
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
}



int binarySearch(vector<int> &v,int m)
{
	int mid=0;
	int low=0;
	int hight=v.size()-1;
	while(low<=hight)
	{
		mid=(low+hight)/2;
		if(v[mid]==m)break;
		if(v[mid]<m)
			low=mid+1;
		else
			hight=mid-1;
	}

	if(v[mid]==m)
	{
		print(v,m,true);
		return m;
	}
	else
	{
		print(v,m,false);
		return -1;
	}
}

int initfb(vector<int> &v,int m)
{
	int s=0;
	int f=1;
	int i=0;
	v.push_back(s);
	while(i++<m)
	{
		f=f+s;
		s=f-s;
		v.push_back(f);
	}
	cout<<"创建斐波那契序列："<<endl;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}


int fbSearch(vector<int> &v,int m)
{
	vector<int> fb;
	initfb(fb,10);
	int mid=0;
	int low=0;
	int hight=v.size()-1;
	int i=4;
	v.pop_back();v.pop_back();//pop2次，10->8  构造集合数目为fibonacci序列数
	while(low<=hight)
	{
		mid=low+fb[i];
		if(v[mid]==m)break;
		if(v[mid]<m)
		{
			low=mid+1;
			i-=2;
		}
		else
		{
			hight=mid-1;
			i--;
		}
	}
	if(v[mid]==m)
	{
		print(v,m,true);
		return m;
	}
	else
	{
		print(v,m,false);
		return -1;
	}
}

