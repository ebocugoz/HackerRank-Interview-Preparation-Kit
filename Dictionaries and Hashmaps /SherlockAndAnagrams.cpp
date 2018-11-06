// Question: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

bool checkAnagram(string s1,string s2)
{
    int dict[128]={0};
    for(int i=0;i<s1.length();i++)
    {
        dict[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++)
    {
        dict[s2[i]]--;
    }
    
    for(int i=0;i<128;i++)
    {
        if(dict[i]!=0)
            return false;
    }
    cout<<s1<<" = "<<s2<<endl;
    return true;
}
vector<string> allSubsets(string s)
{
    vector<string> subsets;
    int len = s.length();
    string sub ="";
    for(int i=0;i<len;i++){
        for(int j= len-i;j>=0;j--){
            sub = s.substr(i,j);
            cout<<sub<<endl;
            if(sub!="")
    {            subsets.push_back(sub);
                }    }
    }
    return subsets;
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
        
    vector<string> subsets = allSubsets(s);
    int subsetSize = subsets.size();
    int counter = 0;
    for(int i=0;i<subsetSize-1;i++){
        for(int j= i+1;j<subsetSize;j++){
           if((subsets[i].length()==subsets[j].length())&&checkAnagram(subsets[i],subsets[j]))
               counter++;
    }
    }
    return counter ;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

