using namespace std;
#include<iostream>
#include<vector>
int p=31;
int n=1e5+7,m=1e9+7;
vector<long long >powers(n);
int main()
{
    string s1="ka";
    string s2="khushalkaborse";
    int l1=s1.size();
    int l2=s2.size();
    powers[0]=1;
    for(int i=1;i<n;i++)
    {
        powers[i]=(p*powers[i-1])%m;
    }
    vector<long long>hash(l2+1,0);
    for(int i=0;i<l2;i++)
    {
        hash[i+1]=(hash[i]+(s2[i]-'a'+1)*powers[i])%m;

    }
    long long hs=0;
    for(int i=0;i<l1;i++)
    {
        hs=(hs+(s1[i]-'a'+1)*powers[i])%m;
    }
    for(int i=0;i+l1-1<l2;i++)
    {
        long long cur_h=(hash[i+l1]-hash[i]+m)%m;
        if(cur_h==(hs*powers[i])%m)

        {
            cout<<"Found at index :"<<i<<endl;
        }
    }
    return 0;
}
