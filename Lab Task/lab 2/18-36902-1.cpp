#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main()
{
    string str;
    int eqCount=0;

    cout<<"Input: ";
    getline(cin,str);
    cout<<endl;
    str=removeSpaces(str);

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='=')
        {
            eqCount++;
        }
    }
    if(eqCount!=1)
    {
        cout<<"Invalid Expression"<<endl;
        return 0;
    }

    cout<<"Output: ";
    for(int i=0;i<str.length();i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            cout<<"<id,"<<(i+1)<<">";
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            cout<<"<"<<str[i]<<","<<(i+1)<<">";
        }
        else if(str[i]=='+')
        {
            cout<<"<+,"<<(i+1)<<">";
        }
        else if(str[i]=='-')
        {
            cout<<"<-,"<<(i+1)<<">";
        }
        else if(str[i]=='*')
        {
            cout<<"<*,"<<(i+1)<<">";
        }
        else if(str[i]=='/')
        {
            cout<<"</,"<<(i+1)<<">";
        }
        else if(str[i]=='%')
        {
            cout<<"<%,"<<(i+1)<<">";
        }
        else if(str[i]=='=')
        {
            cout<<"<=,"<<(i+1)<<">";
        }
        else
        {
            cout<<"Invalid Expression"<<endl;
            return 0;
        }
    }
    cout<<endl;

    return 0;
}
