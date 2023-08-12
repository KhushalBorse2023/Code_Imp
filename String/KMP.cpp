using namespace std;
#include<iostream>
#include<vector>
vector<int>prefix_array(string s)
{
    int j;
    vector<int>ans(s.length());
    for(int i=1; i<s.length(); i++)
    {
        j=ans[i-1];

        while(j>0 and s[i]!=s[j])
        {
            j=ans[j-1];

        }
        if(s[i]==s[j])
        {
            j++;
        }
        ans[i]=j;
    }
    return ans;
}


int main()
{
    string s1="ka";
    string s2="khushalkaborse";
    vector<int>prefix=prefix_array(s1);
    int i=0,j=0;
    int pos=-1;

    while(i<s2.length())
    {
        if(s2[i]==s1[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=prefix[j-1];
            }
            else
            {
                i++;
            }

        }
        if(j==s1.size())
        {
            pos=i-s1.size();
            break;

        }
    }
    cout<<"Position is : "<<pos;

    return 0;
}
