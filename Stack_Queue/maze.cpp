#include<stack>
#include<iostream>
#include<vector>
using namespace std;

typedef struct ways //·���ϵĵ�
{
	int x;
	int y;
	int dir;
}ways;

typedef struct maze
{
	vector<vector<int> > M;
	ways in;
	ways out;
	int n;//�Թ�γ��
	maze():M(10,vector<int>(10,0)),n(10){};
}maze;


void initmaze(maze &m)
{
	int n =m.n;

	m.in.x=1;
	m.in.y=0;
	m.out.x=8;
	m.out.y=9;

	for(int i=0;i<n*n;i++)
	{
		if(i/n==0||i/n==9||i%n==0||i%n==9)
			m.M[i/n][i%n]=1;
	}

	m.M[1][3]=1;
	m.M[1][7]=1;
	m.M[2][3]=1;
	m.M[2][7]=1;
	m.M[3][5]=1;
	m.M[3][6]=1;
	
	m.M[4][2]=1;
	m.M[4][3]=1;
	m.M[4][4]=1;
	
	m.M[5][4]=1;
	m.M[6][2]=1;
	m.M[6][6]=1;
	
	m.M[7][2]=1;
	m.M[7][3]=1;
	m.M[7][4]=1;
	m.M[7][6]=1;
	m.M[7][7]=1;
	m.M[8][1]=1;
	
	m.M[m.in.x][m.in.y]=0;
	m.M[m.out.x][m.out.y]=0;
}

void printway(maze &m,vector<vector<int> > &v) //���ӻ���ʾ
{
	
	for(int i=0;i<(m.n*m.n);i++)
	{
		if(v[i/m.n][i%m.n]==2)
			cout<<".";
		else if(m.M[i/m.n][i%m.n]==0)
			cout<<" ";		
		else if(m.M[i/m.n][i%m.n]==1)
			cout<<"#";
		if((i%m.n)==(m.n-1))cout<<endl;
	}
}

void findWay(maze &m)
{
	stack<ways> s;
	vector<vector<int> > status(m.M);
	ways nowloc={1,0,0};
	s.push(nowloc);
	while((!s.empty())&&(nowloc.x!=m.out.x||nowloc.y!=m.out.y))
	{
		nowloc = s.top();
		if(nowloc.x<0||nowloc.y<0||status[nowloc.x][nowloc.y]==1)//�㲻����  //||status[nowloc.x][nowloc.y]==2
		{
			s.pop();
			continue;
		}
		
		if(nowloc.dir<4) //��һ����
		{
			s.top().dir++;
			status[nowloc.x][nowloc.y]=2;
			
			if(nowloc.dir==0)
				nowloc.x++;
			else if(nowloc.dir==1)
				nowloc.y--;
			else if(nowloc.dir==2)
				nowloc.x--;
			else if(nowloc.dir==3)
				nowloc.y++;
			if(status[nowloc.x][nowloc.y]!=2)// ����ǹ켣�ϵĵ㣬����
			{
				nowloc.dir=0;
				s.push(nowloc);
			}
		}
		else //����ͬ
		{
			s.pop();
			status[nowloc.x][nowloc.y]=1;
		}
	}
	if(s.empty())
	{
		cout<<"���Թ��޽⣡����"<<endl;
	}
	else
		printway(m,status);
}

//ĩ���Թ�
void outMaze()
{
	maze m;
	initmaze(m);
	findWay(m);
}
