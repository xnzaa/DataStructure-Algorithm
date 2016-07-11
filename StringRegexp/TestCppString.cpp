#include<iostream>
#include<string>
#include<vector>

using namespace std;


//�ַ����ָ��
vector<string> split(string str,string pattern)  
{  
    int pos;  
    vector<string> result; 
	int i=0;
	while(true){		
        pos=str.find(pattern,i);  
        if(pos>0&&i<str.size())  
        {  
            result.push_back(str.substr(i,pos-i));  
            i=pos+pattern.size();  
        }
		else
		{
			result.push_back(str.substr(i,str.size())); 
			break;
		}
    }  
    return result;  
}  


void TestCppString()
{
	//����
	string s1 = "aaa";  
    string s2 = s1;//��ͬ���ݣ���ͬ���󣬲�ͬ��ַ
    if(s2 == s1){  
        cout<<"s2 = s1"<<endl;  
    }  
	string s3("value");   
    string s4(10, 'c');
	cout<<s4<<endl;

	cout<<sizeof(s1)<<endl;//16
	cout<<s1.size()<<endl;//3
	cout<<s1.length()<<endl;//3
	cout<<s1.compare(s2)<<endl;//0
	cout<<s1+s2<<endl;//aaaaaa
	cout<<s1.substr(1)<<endl;//aa
	cout<<s3.find("ue",0)<<endl;//3
	cout<<s1.insert(s1.size(),"bcd")<<endl;//aaabcd
	cout<<s1.replace(s1.size()-3,s1.size(),"efg")<<endl;//aaaefg
	cout<<s1.capacity()<<endl;
	cout<<s1[2]<<endl;
	cout<<s1.c_str()<<endl;
	itoa(123,s1.begin(),10);
	cout<<s1<<endl;//litoa() ��������ֵת��Ϊ�ַ���  ultoa()
	s1="21";
	cout<<atoi(s1.c_str())<<endl;

//	����2��
	cout<<split("a,b,c",",")[2]<<endl;
}


/*
c++sleep������
<iostream.h>
	_sleep(ms);
<unistd.h>
	sleep(ms);
*/