#include<iostream>
#include<string>
using namespace std;


char** split(char str[],char* pattern)  
{  

	char *p;
	char * result[50];
	int i=1;
	p=strtok(str,pattern);
	result[i]=p;
	while(p)
	{
		cout<<p<<endl;
		p=strtok(NULL,pattern);
		result[i]=p;
		i++;
	}

	return result;
}  



void TestCString()
{
	char * s1="121";//size=4 len=3 �ַ������ڳ�������
	char s2[]="222";//size=4 len=3 �ַ���������������
	char s3[10]="333";//size=10 len=3 ���������Զ����'\0'(�ַ��������ַ�������)
//	s2="444";// ���벻ͨ��
	s1="121";// ����ͨ��
	cout<<strlen(s3)<<endl;
	cout<<sizeof(s3)<<endl;

	//C�ַ������������淶 strxxx() 
	//ע�⣺C���Ե���غ���������������⣬��copy/catǰӦȷ�ϴ�С���㣬������ܻ����
	cout<<strcmp(s1,s2)<<endl;//��ѡn ��ʾǰn��
	cout<<strcat(s3,s1)<<endl;//��ѡn ��ʾs1ǰn��
	cout<<strcpy(s3,s1)<<endl;//��ѡn ��ʾs1ǰn��
	cout<<strchr(s1,'2')<<endl;
	cout<<strstr(s1,"21")<<endl;
    //����1��
	char str[]="a,b,c";
	cout<<split(str,",")[2]<<endl;
}



/*

//��Ϊ��VC6.0���޷����룬��ע�͵��ˣ����ǳ����Ѿ�ȷ������G++����������
#include<regex.h>

void Regex()
{
    const char * pRegexStr = "[a-z].*";  
    const char * pText = "hello";  
   
    regex_t oRegex;  
    int nErrCode = 0;  
    char szErrMsg[1024] = {0};
    size_t unErrMsgLen = 0;  
   
    if ((nErrCode = regcomp(&oRegex, pRegexStr, 0)) == 0)  
    {  
        if ((nErrCode = regexec(&oRegex, pText, 0, NULL, 0)) == 0)  
        {  
            cout<<pText<<" matches: "<<pRegexStr<<endl; 
            regfree(&oRegex);  
            return 0;  
        }
    }
    unErrMsgLen = regerror(nErrCode, &oRegex, szErrMsg, sizeof(szErrMsg));  
    unErrMsgLen = unErrMsgLen < sizeof(szErrMsg) ? unErrMsgLen : sizeof(szErrMsg) - 1;  
    szErrMsg[unErrMsgLen] = '\0';  
    cout<<"ErrMsg:  "<<szErrMsg<<endl;  
    regfree(&oRegex);  
    return 0;
}*/