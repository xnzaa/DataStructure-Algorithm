/*
�����ඨ��
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

//ģ��ı���������ƣ�Ҫ��ģ�溯����ʵ�ַŵ�ͷ�ļ��У����ܷŵ�Դ�ļ���

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
		if(root == NULL)//��Ҷ�ӽڵ���
		{
			root= s.top();
			s.pop();
			continue;
		}
		cout<<root->data<<endl;//����ڵ�
		s.push(root->rchild);
		root = root->lchild;//��ǰ����Ϊ����
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
	while(!s.empty())  //ÿ����ѭ���������¡�������
	{
		while(root = s.top())//�ҵ����½�Ԫ��
		{
			s.push(root -> lchild);
		}
		s.pop();   //ɾȥ��ָ��
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
	tree_node <T> * oldnode=NULL;//����ǰһ���ڵ㣬�ж��Ƿ��Ǵ��ҽڵ㷵��
	stack<tree_node<T> *> s;
	s.push(root);
	while(!s.empty())  //ÿ����ѭ���������¡�������
	{
		while(root = s.top())//�ҵ����½�Ԫ��
		{
			s.push(root -> lchild);
		}
		s.pop();
		root = s.top();
		cout<<root->data<<endl;//�������
		oldnode = root;
		s.empty()? NULL:s.pop();
		root=(s.empty()? NULL:s.top());//���ظ��ڵ�
		while(!s.empty())
		{
			if(root->rchild==oldnode)//���ҽڵ㷵�أ�����������ڵ�
			{
				cout<<root->data<<endl;
				oldnode=root;
				s.empty()? NULL:s.pop();
				s.empty()? NULL:root = s.top(); 
			}
			else //�����ӷ���,Ϊ����
			{
				s.push(root->rchild);//���ҽڵ㣬��ʼ�µ�����
				break;
			}
		}
	}
}


#endif
