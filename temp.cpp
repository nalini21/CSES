#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
string ans;
void printallstrings(string set, int k, string seq){
    if(k==0)
    {
        ans = ans+seq+',';
        return;
    }
    for(int i=0;i<(int)set.length();i++){
        string nseq="";
        nseq = seq + set[i];
        printallstrings(set, k-1, nseq);
    }
}

int main(){
    string line;
    while (getline(cin,line))
    {
        string set = "";
        string num = "";
        int i=0;
        while(isdigit(line[i]))
            num+= line[i++];
        int k= stoi(num);
        map<char, int> mp;
        for(int j=i+1;j<line.length();j++){
            if(mp.find(line[j])==mp.end())
                set = set+line[j];
            mp[line[j]]=1;
        }
        sort(set.begin(), set.end());
        string seq = "";
        printallstrings(set, k, seq);
        string anss = "";
        for(int i=0;i<(int)ans.length()-1;i++)
            anss += ans[i];
        cout<<anss<<"\n";
    }
    return 0;

}