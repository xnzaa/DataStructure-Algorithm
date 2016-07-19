#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;




class TreeNode
{
public:
	int index;//值的索引
	int weight;
	int parent;
	int lchild;
	int rchild;
	TreeNode():index(-1),weight(-1),parent(-1),lchild(-1),rchild(-1)
	{}
	TreeNode(int in,int we):parent(-1),lchild(-1),rchild(-1)
	{
		index = in;
		weight = we;
	}
	TreeNode(int in,int we,int pa,int lc,int rc)
	{
		index = in;
		weight = we;
		parent = pa;
		lchild = lc;
		rchild = rc;
	}
	bool operator >(TreeNode t2)
	{
		return weight>t2.weight;
	}
};

class com
{
public:
	bool operator()(TreeNode &a,TreeNode &b)
	{
		return a.weight<b.weight;
	}
};

bool compare(TreeNode &a,TreeNode &b)
{
	return a.weight<b.weight;
 } 


void ttree(vector<TreeNode> &T,int i)
{

	if(T[i].index==-1)//非叶节点
	{
		T[T[i].lchild].parent=i;
		T[T[i].rchild].parent=i;
		ttree(T,T[i].lchild);
		ttree(T,T[i].rchild);
	}
}

void HuffmanTree()
{
	//以序列 a:1 b:1 c:2 d:2 e:3 为例
	vector<int> num(5,0);
	num[0]=1;num[1]=1;num[2]=2;num[3]=2;num[4]=3;
	vector<string> con(5);
	con[0]="a";con[1]="b";con[2]="c";con[3]="d";con[4]="e";
	vector<TreeNode> tree;//保存构造的Huffman树
	vector<TreeNode> temp;//构造过程 频率 临时数组
	
	for(int j=0;j<con.size();j++)
	{
		temp.push_back(TreeNode(j,num[j]));
	}
	
	for(;temp.size()>1;)
	{
		sort(temp.begin(),temp.end(),compare);
		TreeNode t1(*temp.begin());
		TreeNode t2(*(temp.begin()+1));
		tree.push_back(t1);
		tree.push_back(t2);
		TreeNode t3;
		t3.lchild=tree.size()-1;
		t3.rchild=tree.size()-2;
		t3.weight=t1.weight+t2.weight;
		temp.erase(temp.begin());
		temp.erase(temp.begin());
		temp.push_back(t3);
	}
	tree.push_back(*temp.begin());

	for(int i=0;i<tree.size();i++)
	{
		cout<<"weight: "<<tree[i].weight;
		if(tree[i].index!=-1)
			cout<<" contain:  "<<con[tree[i].index];
		cout<<endl;
	}
	ttree(tree,tree.size());//遍历树，构造parent
}

