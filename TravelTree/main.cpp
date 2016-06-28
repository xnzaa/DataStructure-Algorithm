#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<string>
#include<set>
#include<map>
#include"tree.h"
using namespace std;

/*

 ½á¹¹  £º    
	 0
   1   2
  3 4 5  6 

*/

int main()
{
	tree<int> tree;

	tree_node<int> pnode(1);

	tree_node<int> lnode1(1);
	tree_node<int> rnode1(2);

	tree_node<int> lnode2(3);
	tree_node<int> rnode2(4);

	tree_node<int> lnode3(5);
	tree_node<int> rnode3(6);

	tree.root = & pnode;
	tree.root->data=0;
	tree.root->lchild= &lnode1;
	tree.root->rchild= &rnode1;
	
	lnode1.lchild= &lnode2;
	lnode1.rchild= &rnode2;
	
	rnode1.lchild= &lnode3;
	rnode1.rchild= &rnode3;

	tree.pre_travel2(tree.root);

	return 0;
}
