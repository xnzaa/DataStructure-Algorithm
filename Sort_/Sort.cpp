#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int num=10000;
const int max=100;

void sort_print(vector<int> &v,double time)
{
	cout<<"排序结果为："<<endl;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<" "<<endl;
	}
	cout<<"共耗时："<<time<<"(ms)"<<endl;
}

void init(vector<int> &v)
{
	srand(1);
	for(int i=0;i<num;i++)
	{
		v.push_back(rand()%max+1);//rand()/double(RAND_MAX)
	}
}

//选择排序
//直接选择排序
void select_sort(vector<int> &v)
{
	double start=clock();
	int min=0;
	for(int i=0;i<v.size();i++)
	{
		min=i;
		for(int j=i+1;j<v.size();j++)
		{
			if(v[min]>v[j])
				min=j;
		}
		swap(v[i],v[min]);

	}
	double end=clock();
	sort_print(v,end-start);
}

//堆排序
void adjustheap(vector<int> &heap,int s)
{
	int tmp=heap[s];
	for(int j=2*s;j<heap.size();j=j*2)
	{
		if(j<(heap.size()-1)&&heap[j]>heap[j+1])
		{
			j++;
		}
		if(heap[s]>heap[j])
		{
			swap(heap[s],heap[j]);
			s=j;
		}
		else
			break;
	}
	heap[s]=tmp;
}

void heap_sort(vector<int> &v)
{
	double start=clock();
	
	vector<int> heap(v);
	v.clear();
	//建堆
	for(int i=heap.size()/2;i>=0;i--)
	{
		adjustheap(heap,i);
	}
	//输出并调整堆
	for(int j=heap.size();j>0;j--)
	{
		v.push_back(heap[0]);
		heap[0]=heap.back();
		heap.pop_back();
		adjustheap(heap,0);
	}
	double end=clock();

	sort_print(v,end-start);
}



//插入排序
//直接插入排序
void insert_sort(vector<int> &v)
{
	double start=clock();
	int tmp=0;
	for(int i=1;i<v.size();i++)
	{
		tmp=v[i];
		for(int j=i;j>0;j--)
		{
			if(v[j-1]>tmp)
				swap(v[j],v[j-1]);
			else
				break;
		}
		swap(v[j],tmp);
	}
	double end=clock();
	sort_print(v,end-start);
}

//希尔排序
void shell_sort(vector<int> &v)
{
	double start=clock();
	int tmp =0;
	for(int m=v.size()/2;m>0;m=m/2)//shell排序 + 直接插入排序
	{
		for(int i=0;i<v.size();i=i+m)
		{
			tmp=v[i];
			for(int j=i;j-m>0;j=j-m)
			{
				if(v[j-m]>tmp)
					v[j]=v[j-m];
				else
					break;
			}
			v[j]=tmp;
		}
	}
	double end=clock();
	sort_print(v,end-start);
}

//交换排序
//冒泡排序
void bubble_sort(vector<int> &v)
{
	double start=clock();
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v.size()-i-1;j++)
		{
			if(v[j+1]<v[j])
				swap(v[j+1],v[j]);
		}
	}
	double end=clock();
	sort_print(v,end-start);
}

//快速排序
void quick(vector<int> &v,int start,int end)
{
	if(start>end) return;//返回条件
	int tmp;
	tmp=v[end];
	for(int i=start,j=end;i<j;)
	{
		while(v[i]<=tmp&&i<j)	i++; //相等情况下也要继续
		v[j]=v[i];
		while(v[j]>=tmp&&i<j)	j--; //相等情况下也要继续
		v[i]=v[j];
	}
	v[i]=tmp;
	quick(v,start,i-1);//递归
	quick(v,i+1,end);
}

void quick_sort(vector<int> &v)
{
	double start=clock();
	quick(v,0,v.size()-1);
	double end=clock();
	sort_print(v,end-start);
}


//归并排序
void merge(vector<int> &v,int low,int mid,int hight)
{
	vector<int> vtmp;
	int i=low,j=mid+1;
	while(i<=mid&&j<=hight)
	{
		while(i<=mid&&v[i]<=v[j])//注意相等的情况
			vtmp.push_back(v[i++]);
		while(j<=hight&&v[j]<v[i])
			vtmp.push_back(v[j++]);
	}
	while(i>mid&&j<=hight)
		vtmp.push_back(v[j++]);
	while(j>hight&&i<=mid)
		vtmp.push_back(v[i++]);
	for(int n=low;n<=hight;n++)
		v[n]=vtmp[n-low];
}

void merge_sort(vector<int> &v1,int low,int hight)
{
	if(low<hight)
	{
		int mid=(low+hight)/2;
		merge_sort(v1,low,mid);
		merge_sort(v1,mid+1,hight);
		merge(v1,low,mid,hight);
	}
}

void merge_2_sort(vector<int> &v)
{
	double start=clock();

	merge_sort(v,0,v.size()-1);

	double end=clock();
	sort_print(v,end-start);
}

//基数排序
//按照低位优先，对1-20  2位数进行排序
void distribute(vector<int> &v,vector<vector<int> > &vv,int redix)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		vv[(*it)%(int)(pow(10,redix+1))/pow(10,redix)].push_back(*it);
}

void collect(vector<int> &v,vector<vector<int> > &vv,int redix)
{
	int count=0;
	for(int i=0;i<10;i++)
	{
		for(vector<int>::iterator it=vv[i].begin();it!=vv[i].end();it++)
		{
			v[count]=*it;
			count++;
		}
	}
}

void radix_sort(vector<int> &v)
{
	double start=clock();

	vector<vector<int> > vv(10);
	for(int i=0;i<log10(max)+1;i++)
	{
		vv.swap(vector<vector<int> > (10));
		distribute(v,vv,i);
		collect(v,vv,i);
	}
	double end=clock();
	sort_print(v,end-start);
}//	_sleep(0);