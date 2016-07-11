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
	char * s1="121";//size=4 len=3 字符串放在常量区域
	char s2[]="222";//size=4 len=3 字符串保存在数组中
	char s3[10]="333";//size=10 len=3 编译器会自动添加'\0'(字符数组与字符串区别)
//	s2="444";// 编译不通过
	s1="121";// 编译通过
	cout<<strlen(s3)<<endl;
	cout<<sizeof(s3)<<endl;

	//C字符串函数命名规范 strxxx() 
	//注意：C语言的相关函数并不做容量检测，在copy/cat前应确认大小满足，否则可能会出错
	cout<<strcmp(s1,s2)<<endl;//可选n 表示前n个
	cout<<strcat(s3,s1)<<endl;//可选n 表示s1前n个
	cout<<strcpy(s3,s1)<<endl;//可选n 表示s1前n个
	cout<<strchr(s1,'2')<<endl;
	cout<<strstr(s1,"21")<<endl;
    //方法1：
	char str[]="a,b,c";
	cout<<split(str,",")[2]<<endl;
}



/*

//因为在VC6.0中无法编译，就注释掉了，但是程序已经确认能在G++中正常运行
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