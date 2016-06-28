/*
树的类定义
*/
#ifndef __TREE_H
#define __TREE_H

#include<iostream>
#include<stack>
#include<queue>

//template <typename T1,typename T2>
template <typename T1>
class tree_node
{
private:

public:
	T1 data;
	tree_node * lchild;
	tree_node * rchild;

	tree_node()
	{
		lchild=NULL;
		rchild=NULL;
	}

	tree_node(T1 d)
	{
		data=d;
		lchild=NULL;
		rchild=NULL;
	}
//	bool operator==(tree_node * ,tree_node *);
};

template <typename T>
class tree
{
private:

public:
	tree_node<T> * root;
	void pre_travel1(const tree_node<T> *) const;
	void mid_travel1(const tree_node<T> *) const;
	void post_travel1(const tree_node<T> *) const;
	void level_travel(tree_node<T> *);
	void pre_travel2(tree_node<T> *);
	void mid_travel2(tree_node<T> *);
	void post_travel2(tree_node<T> *);
};

//模版的本质与宏类似，要把模版函数的实现放到头文件中，不能放到源文件中

template <typename T>
void tree<T>::pre_travel1(const tree_node<T> * root)  const
{
	if(root == NULL) return;
	cout<<root->data<<endl;
	pre_travel1(root->lchild);
	pre_travel1(root->rchild);
}

template <typename T>
void tree<T>::mid_travel1(const tree_node<T> * root) const
{
	if(root == NULL) return;
	mid_travel1(root->lchild);
	cout<<root->data<<endl;
	mid_travel1(root->rchild);
}

template <typename T>
void tree<T>::post_travel1(const tree_node<T> * root) const
{
	if(root == NULL) return;
	post_travel1(root->lchild);
	post_travel1(root->rchild);
	cout<<root->data<<endl;
}

template <typename T>
void tree<T>::level_travel(tree_node<T> * root) 
{
	queue<tree_node<T> *> q;
	q.push(root);
	while(!q.empty())
	{
		root= q.front();
		cout<<root->data<<endl;
		if(root->lchild)
			q.push(root->lchild);
		if(root->rchild)
			q.push(root->rchild);
		q.pop();
	}
}

template <typename T>
void tree<T>::pre_travel2(tree_node<T> * root)
{
	stack<tree_node<T> *> s;
	s.push(root);
	while(!s.empty())//
	{
		if(root == NULL)//到叶子节点了
		{
			root= s.top();
			s.pop();
			continue;
		}
		cout<<root->data<<endl;//输出节点
		s.push(root->rchild);
		root = root->lchild;//当前变量为左孩子
	}
}

template <typename T>
void tree<T>::mid_travel2(tree_node<T> * root)
{
	stack<tree_node<T> *> s;
//	if(root == NULL)
//	{
//		return;
//	}
	s.push(root);
	while(!s.empty())  //每个新循环，都是新“树根”
	{
		while(root = s.top())//找到左下角元素
		{
			s.push(root -> lchild);
		}
		s.pop();   //删去空指针
		if(!s.empty())
		{
			root = s.top();
			s.pop();
			cout<<root->data<<endl;
			s.push(root -> rchild);
		}
	}
}

template <typename T>
void tree<T>::post_travel2(tree_node<T> * root)
{
	tree_node <T> * oldnode=NULL;//保存前一个节点，判断是否是从右节点返回
	stack<tree_node<T> *> s;
	s.push(root);
	while(!s.empty())  //每个新循环，都是新“树根”
	{
		while(root = s.top())//找到左下角元素
		{
			s.push(root -> lchild);
		}
		s.pop();
		root = s.top();
		cout<<root->data<<endl;//输出左孩子
		oldnode = root;
		s.empty()? NULL:s.pop();
		root=(s.empty()? NULL:s.top());//返回父节点
		while(!s.empty())
		{
			if(root->rchild==oldnode)//从右节点返回，继续输出根节点
			{
				cout<<root->data<<endl;
				oldnode=root;
				s.empty()? NULL:s.pop();
				s.empty()? NULL:root = s.top(); 
			}
			else //从左孩子返回,为新树
			{
				s.push(root->rchild);//有右节点，开始新的搜索
				break;
			}
		}
	}
}


#endif
