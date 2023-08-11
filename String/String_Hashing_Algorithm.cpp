using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
int p=31;
int N=1e5+3,m=1e9+7;
vector<long long>Powers(N);
long long calculate_hash(string x)
{
    long long hash=0;
    for(int i=0;i<x.length();i++)
    {

        hash=(hash+(x[i]-'a'+1)*Powers[i])%m;
    }
    return hash;
}

int main()
{
    Powers[0]=1;
    for(int i=1; i<N; i++)
    {

        Powers[i]=(Powers[i-1]*p)%m;

    }
    vector<string>str= {"aa","ab","ca","aa"};
    vector<long long>hashes;
    for(auto x:str)
    {
     hashes.push_back(calculate_hash(x));
    }
    sort(hashes.begin(),hashes.end());
    int distinct =0;
    for(int i=0;i<hashes.size();i++)
    {

        if(i==0 or hashes[i]!=hashes[i-1])
        {

            distinct++;
        }
    }
cout<<distinct<<"\n";

    return 0;
}
