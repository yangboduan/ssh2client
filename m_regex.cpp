/*

正则说明: ---->详细请参考:正则表达式30分钟入门教程
 . 匹配除换行符以外的任意字符 
 \w 匹配字母或数字或下划线或汉字 
 \s 匹配任意的空白符 
 \d 匹配数字 
 ^ 匹配字符串的开始 
 $ 匹配字符串的结束 
 * 重复零次或更多次 
 + 重复一次或更多次 
 ? 重复零次或一次 
 {n} 重复n次 
 {n,} 重复n次或更多次 
 {n,m} 重复n到m次 
 | 代表或者的关系 
 [xx] xx代表匹配的内容 


*/
#include <iostream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
//利用正则表达式输出接口IP地址信息
string print_IPAddr_regex(const string& str){
    regex reg("(\\d+.\\d+.\\d+.\\d+.)");
    string::const_iterator start(str.begin()),
                            end(str.end());
    match_results<string::const_iterator> what;
    string res("");
    while (regex_search(start,end,what,reg,match_default)){
        res+=what[1]+"\n";
        start=what[0].second;
    }
    if (res.length() >0)
    {
    cout<<"IP address of interface: "<<endl;
    cout<<res; 
    }
    return res;
}

//利用正在表达式输出接口信息
string print_interface_regex(const string& str){
    regex reg("(FastEthernet\\d+\\/\\d+)|(Vlan\\d+)");
    string::const_iterator start(str.begin()),
                            end(str.end());
    match_results<string::const_iterator> what;
    string res("");
    while (regex_search(start,end,what,reg,match_default)){
        res+=what[1]+"\n"+what[2]+"\n";
        start=what[0].second;
    }
    if (res.length() >0)
    {
    cout<<"IP address of interface: "<<endl;
    cout<<res; 
    }
    return res;
}




//利用正在表达式输出接口和IP地址的对应关系
string print_interface_IPAddr_regex(const string& str){
    int n=0;
    regex reg("(FastEthernet\\d+\\/\\d+|Vlan\\d+)\\s+(\\d+.\\d+.\\d+.\\d+.)");
    string::const_iterator start(str.begin()),
                            end(str.end());
    match_results<string::const_iterator> what;
    string res("");
    while (regex_search(start,end,what,reg,match_default)){
	n++;
        res+=what[1]+"-----------"+what[2]+"\n";
        start=what[0].second;
    }
    if (res.length() >0)
    {
    cout<<"IP address of interface: "<<endl;
    cout<<res;
    cout<<"match counts:"<<n<<endl; 
    }
    return res;
}


//利用正在表达式输入arp表，IP和MAC地址的对应关系
string print_arp_regex(const string& str){
    int n=0;
    regex reg("(\\d+\\.\\d+\\.\\d+\\.\\d+)\\s+[0-9-]+\\s+([A-Za-z0-9]{4}\\.[A-Za-z0-9]{4}\\.[A-Za-z0-9]{4})\\s+");
    string::const_iterator start(str.begin()),
                            end(str.end());
    match_results<string::const_iterator> what;
    string res("");
    while (regex_search(start,end,what,reg,match_default)){
	n++;
        res+=what[1]+"-----------"+what[2]+"\n";
        start=what[0].second;
    }
    if (res.length() >0)
    {
    cout<<"infomation of arp  "<<endl;
    cout<<res;
    cout<<"match counts:"<<n<<endl; 
    }
    return res;
}


//利用正在表达式输入mac表，vlan-MAC-interface地址的对应关系
string print_MACTable_regex(const string& str){
    int n=0;
    regex reg("(\\d+)\\s+([A-Za-z0-9]{4}\\.[A-Za-z0-9]{4}\\.[A-Za-z0-9]{4})\\s+\\w+\\s+([a-zA-Z0-9/]+)");
    string::const_iterator start(str.begin()),
                            end(str.end());
    match_results<string::const_iterator> what;
    string res("");
    while (regex_search(start,end,what,reg,match_default)){
	n++;
        res+=what[1]+"-----------"+what[2]+"------------"+what[3]+"\n";
        start=what[0].second;
    }
    if (res.length() >0)
    {
    cout<<"infomation of MAC table"<<endl;
    cout<<res;
    cout<<"match counts:"<<n<<endl; 
    }
    return res;
}

