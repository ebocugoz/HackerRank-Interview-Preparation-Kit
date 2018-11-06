// Question : https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    if(s2.length()>s1.length())
        return twoStrings(s2,s1);
    int dict[128] = {0};
    for(int i=0;i<s1.length();i++)
    {
        if(dict[s1[i]]==0)
            dict[s1[i]]++ ;
        
    }
    for(int i=0;i<s2.length();i++)
    {
        if(dict[s2[i]]==1)
            dict[s2[i]]++ ;
        if(dict[s2[i]]==2)
            {
            return "YES";}
        
    }
    cout<<"no"<<endl;
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

