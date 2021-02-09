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
    int plusCount=0;
    int minusCount=0;
    int divCount=0;
    int mulCount=0;
    int modCount=0;

    getline(cin,str);
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
    for(int i=1;i<str.length();i++)
    {
        for(int j=i-1;j<i;j++)
        {
            if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%')
            {
                if(str[j]=='+' || str[j]=='-' || str[j]=='*' || str[j]=='/' || str[j]=='%')
                {
                    cout<<"Invalid Expression"<<endl;
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+')
        {
            plusCount++;
        }
        else if(str[i]=='-')
        {
            minusCount++;
        }
        else if(str[i]=='*')
        {
            mulCount++;
        }
        else if(str[i]=='/')
        {
            divCount++;
        }
        else if(str[i]=='%')
        {
            modCount++;
        }
    }

    cout<<"= operator found: "<<eqCount<<" time(s)"<<endl;
    cout<<"+ operator found: "<<plusCount<<" time(s)"<<endl;
    cout<<"- operator found: "<<minusCount<<" time(s)"<<endl;
    cout<<"/ operator found: "<<divCount<<" time(s)"<<endl;
    cout<<"* operator found: "<<mulCount<<" time(s)"<<endl;
    cout<<"% operator found: "<<modCount<<" time(s)"<<endl;
    return 0;
}
