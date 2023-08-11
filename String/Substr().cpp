using namespace std;
#include<iostream>
#include<string>
int main()
{
    string s1="ka";
    string s2="Khushalkaborseka";
    int n=s1.length();
    int m=s2.length();
    for(int i=0;i<m-n+1;i++)
    {
        if(s2.substr(i,n)==s1)
        {
            cout<<" String Found At : "<< i << endl;

        }
    }


    return 0;
}
